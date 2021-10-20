Feature: Create characters

  Background:
    * url baseUrl
    * def login = call read('../../login/login.feature') { email: 'test1@test.com', password: 'Test1234' }
    * def authorization = login.token
    * configure headers = { Authorization: '#(authorization)' }

  Scenario Outline: Create character with every valid class

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass>' }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    When method get
    Then status 200
    And match response == { characters: [ { name: '<characterName>', className: '<characterClass>', exp: 0 } ] }

    Given path 'protected_api/characters/<characterName>'
    When method delete
    Then status 204

    Examples:
      | characterName      | characterClass |
      | DbApiTestCharacter | wizard         |
      | DbApiTestCharacter | archer         |
      | DbApiTestCharacter | warrior        |
      | DbApiTestCharacter | rogue          |

  Scenario Outline: Get an error when trying to create a character with an invalid class

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass>', exp: 0 }
    When method post
    Then status 400

    Given path 'protected_api/characters'
    When method get
    Then status 404

    Examples:
      | characterName      | characterClass |
      | DbApiTestCharacter | wonky          |
      | DbApiTestCharacter | stillWonky     |

  Scenario Outline: Get an error when trying to create characters with the same name

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass1>' }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass2>' }
    When method post
    Then status 400

    Given path 'protected_api/characters'
    When method get
    Then status 200
    And match response == { characters: [ { name: '<characterName>', className: '<characterClass1>', exp: 0 } ] }

    Given path 'protected_api/characters/<characterName>'
    When method delete
    Then status 204

    Examples:
      | characterName      | characterClass1 | characterClass2 |
      | DbApiTestCharacter | wizard          | archer          |

  Scenario Outline: Create multiple characters

    Given path 'characters'
    When method get
    Then status 404

    Given path 'protected_api/characters'
    And request { name: '<characterName1>', className: '<characterClass1>' }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    And request { name: '<characterName2>', className: '<characterClass2>' }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    When method get
    Then status 200
    And match response == { characters: [ { name: '<characterName1>', className: '<characterClass1>', exp: 0 }, { name: '<characterName2>', className: '<characterClass2>', exp: 0 } ] }

    Given path 'protected_api/characters/<characterName1>'
    When method delete
    Then status 204

    Given path 'protected_api/characters/<characterName2>'
    When method delete
    Then status 204

    Examples:
      | characterName1      | characterClass1 | characterName2      | characterClass2 |
      | DbApiTestCharacter1 | wizard          | DbApiTestCharacter2 | warrior         |

  Scenario: Get error when trying to create an empty character

    Given path 'protected_api/characters'
    And request {}
    When method post
    Then status 400

    Given path 'protected_api/characters'
    When method get
    Then status 404
