Feature: Create characters

  Background:
    * url baseUrl
    * def login = callonce read('../../utils/login.feature') { email: 'test1@test.com', password: 'Test1234' }
    * def authorization = login.token
    * configure headers = { Authorization: '#(authorization)' }
    * def defaultStatistic = { createdTimestamp: #number, lastUsedTimestamp: #number }
    * def defaultColor = { r: 0.0, g: 0.0, b: 0.0, a: 0.0 }
    * def defaultAppearance = { gender: 'f', height: 1.0, faceId: 0, earsId: 0, eyebrowsId: 0, facialHairId: 0, hairId: 0, skinColor: #(defaultColor), eyeColor: #(defaultColor), scarColor: #(defaultColor), tattooColor: #(defaultColor), hairColor: #(defaultColor) }
    * def warriorEquipment = { mainWeapon: 'Shortsword', supportWeapon: 'Wooden Heater Shield', headArmour: '', shoulderArmour: '', torsoArmour: 'Recruit Chestplate', armArmour: 'Recruit Gloves', legArmour: 'Recruit Legwear', footArmour: 'Recruit Boots' }
    * def archerEquipment = { mainWeapon: 'Wooden Bow', supportWeapon: 'Wooden Arrows', headArmour: '', shoulderArmour: '', torsoArmour: 'Strayer Jacket', armArmour: 'Strayer Gloves', legArmour: 'Strayer Trousers', footArmour: 'Strayer Boots' }

    * configure afterScenario =
    """
    function() { karate.call('../../utils/delete_all_characters.feature') }
    """
    * def sleep =
    """
    function(ms) { java.lang.Thread.sleep(ms) }
    """

  Scenario Outline: Create character with every valid class and valid name combinations

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass>', appearance: #(defaultAppearance) }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    When method get
    Then status 200
    And match response == { characters: [ { name: '<characterName>', className: '<characterClass>', exp: 0, appearance: #(defaultAppearance), equipment: <equipment>, statistic: #(defaultStatistic) } ] }

    Examples:
      | characterName             | characterClass | equipment           |
      | AlmostTooLongTestName1234 | Warrior        | #(warriorEquipment) |
      | Ng                        | Warrior        | #(warriorEquipment) |
      | DbApiTestCharacter0       | Archer         | #(archerEquipment)  |
      | Db Api Test Character     | Archer         | #(archerEquipment)  |

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
    And match response == { characters: [ { name: '<characterName>', className: '<characterClass1>', exp: 0, appearance: #(defaultAppearance), equipment: #(warriorEquipment), statistic: #(defaultStatistic) } ] }

    Given path 'protected_api/characters/<characterName>'
    When method delete
    Then status 204

    Examples:
      | characterName      | characterClass1 | characterClass2 |
      | DbApiTestCharacter | Warrior         | Archer          |

  Scenario Outline: Create multiple characters

    Given path 'characters'
    When method get
    Then status 404

    Given path 'protected_api/characters'
    And request { name: '<characterName1>', className: '<characterClass1>', appearance: #(defaultAppearance) }
    When method post
    Then status 201

    * sleep(1000);

    Given path 'protected_api/characters'
    And request { name: '<characterName2>', className: '<characterClass2>', appearance: #(defaultAppearance) }
    When method post
    Then status 201

    Given path 'protected_api/characters'
    When method get
    Then status 200
    And match response == { characters: [ { name: '<characterName2>', className: '<characterClass2>', exp: 0, appearance: #(defaultAppearance), equipment: <characterEquipment2>, statistic: #(defaultStatistic) }, { name: '<characterName1>', className: '<characterClass1>', exp: 0, appearance: #(defaultAppearance), equipment: <characterEquipment1>, statistic: #(defaultStatistic) } ] }
    And def first = response.characters[0].statistic
    And def second = response.characters[1].statistic
    And assert first.createdTimestamp >= second.createdTimestamp
    And assert first.lastUsedTimestamp >= second.lastUsedTimestamp

    Given path 'protected_api/characters/<characterName1>'
    When method delete
    Then status 204

    Given path 'protected_api/characters/<characterName2>'
    When method delete
    Then status 204

    Examples:
      | characterName1      | characterClass1 | characterEquipment1 | characterName2      | characterClass2 | characterEquipment2 |
      | DbApiTestCharacter1 | Warrior         | #(warriorEquipment) | DbApiTestCharacter2 | Archer          | #(archerEquipment)  |

  Scenario: Get error when trying to create an empty character

    Given path 'protected_api/characters'
    And request {}
    When method post
    Then status 400

    Given path 'protected_api/characters'
    When method get
    Then status 404

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
      | ACharacterNameWayTooLong01       | Archer         |
      | A                                | Warrior        |
      | 0StartsWithNumeric               | Archer         |
      | Has_Non/Alpha:Numeric/Characters | Warrior        |
      | Has  RepeatedSpaces              | Archer         |