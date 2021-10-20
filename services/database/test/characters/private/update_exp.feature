Feature: Character management happy cases

  Background:
    * url baseUrl
    * def login = call read('../../login/login.feature') { email: 'test1@test.com', password: 'Test1234' }
    * def userToken = login.token

  Scenario Outline: Update the experience points of a character

    Given path 'protected_api/characters'
    And headers { Authorization: '#(userToken)' }
    And request { name: '<characterName>', className: '<characterClass>' }
    When method post
    Then status 201

    Given path 'private_api/characters/<characterName>/exp/<exp>'
    And headers { Authorization: '#(apiKey)' }
    When method put
    Then status 204

    Given path 'private_api/characters/<characterName>/userId/<userId>'
    And headers { Authorization: '#(apiKey)'}
    When method get
    Then status 200
    And match response == { name: '<characterName>', className: '<characterClass>', exp: <exp> }

    Given path 'protected_api/characters/<characterName>'
    And headers { Authorization: '#(userToken)' }
    When method delete
    Then status 204

    Examples:
      | userId         | characterName      | characterClass | exp        |
      | test1@test.com | DbApiTestCharacter | warrior        | 100        |
      | test1@test.com | DbApiTestCharacter | warrior        | 2000000000 |
