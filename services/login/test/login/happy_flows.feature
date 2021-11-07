Feature: Login happy cases

  Background:
    * url baseUrl

  Scenario Outline: Get token for valid user credentials and session gets invalidated after being finished

    Given path 'public_api/login/challenge'
    And request { nonce: <nonce> }
    When method post
    Then status 200
    And match response == { session_id: #notnull, challenge: #number }
    * def challengeResponse = response.challenge - nonce
    * def sessionId = response.session_id

    Given path 'public_api/login/token'
    And request { session_id: #(sessionId), challenge_response: #(challengeResponse), email: '<email>', password: '<password>' }
    When method post
    Then status 200
    And match response == { id_token: #string, token_type: #string }

    Given path 'public_api/login/token'
    And request { session_id: #(sessionId), challenge_response: #(challengeResponse), email: '<email>', password: '<password>' }
    When method post
    Then status 404

    Examples:
      | nonce | email          | password |
      | 1     | test@test.com  | Test1234 |
      | 2     | test1@test.com | Test1234 |
