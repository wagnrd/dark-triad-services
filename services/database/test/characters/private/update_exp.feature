Feature: Update experience points

  Background:
    * url baseUrl
    * def login = callonce read('../../utils/login.feature') { email: 'test@test.com', password: 'Test1234' }
    * def defaultColor = { r: 0.0, g: 0.0, b: 0.0, a: 0.0 }
    * def defaultAppearance = { gender: 'f', height: 1.0, faceId: 0, earsId: 0, eyebrowsId: 0, facialHairId: 0, hairId: 0, skinColor: #(defaultColor), eyeColor: #(defaultColor), scarColor: #(defaultColor), tattooColor: #(defaultColor), hairColor: #(defaultColor) }

    * configure afterScenario =
    """
    function() { karate.call('../../utils/delete_all_characters.feature') }
    """

  Scenario Outline: Update the experience points of a character

    Given path 'protected_api/characters'
    And headers { Authorization: #(login.authorization) }
    And request { name: '<characterName>', className: '<characterClass>', appearance: #(defaultAppearance) }
    When method post
    Then status 201

    Given path 'private_api/characters/<characterName>/exp/<exp>'
    And headers { Authorization: '#(apiKey)' }
    When method put
    Then status 204

    Given path 'private_api/characters/<characterName>'
    And headers { Authorization: '#(apiKey)'}
    When method get
    Then status 200
    And match response.exp == <exp>

    Examples:
      | characterName      | characterClass | exp        |
      | DbApiTestCharacter | Warrior        | 100        |
      | DbApiTestCharacter | Warrior        | 2000000000 |