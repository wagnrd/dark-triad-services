Feature: Create characters

  Background:
    * url baseUrl
    * def login = call read('../../login/login.feature') { email: 'test1@test.com', password: 'Test1234' }
    * def authorization = login.token
    * configure headers = { Authorization: '#(authorization)' }
    * def defaultColor = { r: 0.0, g: 0.0, b: 0.0, a: 0.0 }
    * def defaultAppearance = { gender: 'f', height: 1.0, faceId: 0, earsId: 0, eyebrowsId: 0, facialHairId: 0, hairId: 0, skinColor: #(defaultColor), eyeColor: #(defaultColor), scarColor: #(defaultColor), tattooColor: #(defaultColor), hairColor: #(defaultColor) }

  Scenario Outline: Create character with every valid class

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass>', appearance: #(defaultAppearance) }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    When method get
    Then status 200
    And match response == { characters: [ { name: '<characterName>', className: '<characterClass>', exp: 0, appearance: #(defaultAppearance) } ] }

    Given path 'protected_api/characters/<characterName>'
    When method delete
    Then status 204

    Examples:
      | characterName             | characterClass |
      | AlmostTooLongTestName1234 | Wizard         |
      | Ng                        | Archer         |
      | DbApiTestCharacter0       | Warrior        |
      | Db Api Test Character     | Rogue          |

  Scenario Outline: Get an error when trying to create a character with an invalid class

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<invalidCharacterClass>', appearance: #(defaultAppearance) }
    When method post
    Then status 400

    Given path 'protected_api/characters'
    When method get
    Then status 404

    Examples:
      | characterName      | invalidCharacterClass |
      | DbApiTestCharacter | wonky                 |
      | DbApiTestCharacter | stillWonky            |

  Scenario Outline: Get an error when trying to create characters with the same name

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass1>', appearance: #(defaultAppearance) }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass2>', appearance: #(defaultAppearance) }
    When method post
    Then status 400

    Given path 'protected_api/characters'
    When method get
    Then status 200
    And match response == { characters: [ { name: '<characterName>', className: '<characterClass1>', exp: 0, appearance: #(defaultAppearance) } ] }

    Given path 'protected_api/characters/<characterName>'
    When method delete
    Then status 204

    Examples:
      | characterName      | characterClass1 | characterClass2 |
      | DbApiTestCharacter | Wizard          | Archer          |

  Scenario Outline: Create multiple characters

    Given path 'characters'
    When method get
    Then status 404

    Given path 'protected_api/characters'
    And request { name: '<characterName1>', className: '<characterClass1>', appearance: #(defaultAppearance) }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    And request { name: '<characterName2>', className: '<characterClass2>', appearance: #(defaultAppearance) }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    When method get
    Then status 200
    And match response == { characters: [ { name: '<characterName1>', className: '<characterClass1>', exp: 0, appearance: #(defaultAppearance) }, { name: '<characterName2>', className: '<characterClass2>', exp: 0, appearance: #(defaultAppearance) } ] }

    Given path 'protected_api/characters/<characterName1>'
    When method delete
    Then status 204

    Given path 'protected_api/characters/<characterName2>'
    When method delete
    Then status 204

    Examples:
      | characterName1      | characterClass1 | characterName2      | characterClass2 |
      | DbApiTestCharacter1 | Wizard          | DbApiTestCharacter2 | Warrior         |

  Scenario: Get error when trying to create an empty character

    Given path 'protected_api/characters'
    And request {}
    When method post
    Then status 400

    Given path 'protected_api/characters'
    When method get
    Then status 404

  Scenario Outline: Custom experience points should be reset when creating a character

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass>', exp: <customExp>, appearance: #(defaultAppearance) }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    When method get
    Then status 200
    And match response == { characters: [ { name: '<characterName>', className: '<characterClass>', exp: <resetExp>, appearance: #(defaultAppearance) } ] }

    Given path 'protected_api/characters/<characterName>'
    When method delete
    Then status 204

    Examples:
      | characterName      | characterClass | customExp | resetExp |
      | DbApiTestCharacter | Wizard         | 9999      | 0        |
      | DbApiTestCharacter | Wizard         | 1111      | 0        |

  Scenario Outline: Get an error when trying to create a character with invalid name

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass>', appearance: #(defaultAppearance) }
    When method post
    Then status 400

    Given path 'protected_api/characters'
    When method get
    Then status 404

    Examples:
      | characterName                    | characterClass |
      | ACharacterNameWayTooLong01       | Wizard         |
      | A                                | Wizard         |
      | 0StartsWithNumeric               | Wizard         |
      | Has_Non/Alpha:Numeric/Characters | Wizard         |