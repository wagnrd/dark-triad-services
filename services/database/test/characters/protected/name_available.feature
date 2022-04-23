Feature: Character name availability

  Background:
    * url baseUrl
    * def login = callonce read('../../utils/login.feature') { email: 'test1@test.com', password: 'Test1234' }
    * def authorization = login.token
    * configure headers = { Authorization: '#(authorization)' }
    * def defaultColor = { r: 0.0, g: 0.0, b: 0.0, a: 0.0 }
    * def defaultAppearance = { gender: 'f', height: 1.0, faceId: 0, earsId: 0, eyebrowsId: 0, facialHairId: 0, hairId: 0, skinColor: #(defaultColor), eyeColor: #(defaultColor), scarColor: #(defaultColor), tattooColor: #(defaultColor), hairColor: #(defaultColor) }

    * configure afterScenario =
    """
    function() { karate.call('../../utils/delete_all_characters.feature') }
    """

  Scenario Outline: Check if character name does not already exist and create a character with the given name

    Given path 'protected_api/characters/<characterName>/exists'
    When method get
    Then status 404

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass>', appearance: #(defaultAppearance) }
    When method post
    Then status 201

    Given path 'protected_api/characters/<characterName>/exists'
    When method get
    Then status 204

    Given path 'protected_api/characters/<characterName>'
    When method delete
    Then status 204

    Given path 'protected_api/characters/<characterName>/exists'
    When method get
    Then status 404

    Examples:
      | characterName       | characterClass |
      | DbApiTestCharacter1 | Warrior        |
      | DbApiTestCharacter2 | Archer         |