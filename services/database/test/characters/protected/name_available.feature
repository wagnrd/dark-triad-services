Feature: Character name availability

  Background:
    * url baseUrl
    * def login = call read('../../login/login.feature') { email: 'test1@test.com', password: 'Test1234' }
    * def authorization = login.token
    * configure headers = { Authorization: '#(authorization)' }

  Scenario Outline: Check if character name does not already exist and create a character with the given name

    Given path 'protected_api/characters/<characterName>/exists'
    When method get
    Then status 404

    Given path 'protected_api/characters'
    And request { name: '<characterName>', className: '<characterClass>' }
    When method post
    Then status 201

    Given path 'protected_api/characters/<characterName>/exists'
    When method get
    Then status 200

    Given path 'protected_api/characters/<characterName>'
    When method delete
    Then status 204

    Examples:
      | characterName      | characterClass |
      | DbApiTestCharacter | wizard         |