Feature: Login happy cases

  Background:
    * url baseUrl

  Scenario Outline: Session not found

    Given path 'login/token'
    And request { session_id: <invalidSessionId>, challenge_response: 0, email: 'some@e.mail', password: 'some-password' }
    When method post
    Then status 404

    Examples:
      | invalidSessionId |
      | 12345            |
      | 67890            |

  Scenario Outline: Get rejected for providing invalid challenge response and session gets invalidated

    Given path 'login/challenge'
    And request { nonce: <nonce> }
    When method post
    Then status 200
    And match response == { session_id: #notnull, challenge: #number }
    * def correctChallengeResponse = response.challenge - nonce
    * def sessionId = response.session_id

    Given path 'login/token'
    And request { session_id: #(sessionId), challenge_response: <invalidChallengeResponse>, email: '<email>', password: '<password>' }
    When method post
    Then status 403

    Given path 'login/token'
    And request { session_id: #(sessionId), challenge_response: #(correctChallengeResponse), email: '<email>', password: '<password>' }
    When method post
    Then status 404

    Examples:
      | nonce | email          | password  | invalidChallengeResponse |
      | 1     | test@test.com  | Test1234  | 123456789                |
      | 2     | test1@test.com | Test12345 | 987654321                |

  Scenario: Get rejected for missing nonce when requesting a challenge

    Given path 'login/challenge'
    When method post
    Then status 400

  Scenario Outline: Get rejected when not providing an email or password

    Given path 'login/challenge'
    And request { nonce: <nonce> }
    When method post
    Then status 200
    And match response == { session_id: #notnull, challenge: #number }
    * def challengeResponse = response.challenge - nonce
    * def sessionId = response.session_id

    Given path 'login/token'
    And request { session_id: #(sessionId), challenge_response: #(challengeResponse), password: '<password>' }
    When method post
    Then status 400

    Given path 'login/token'
    And request { session_id: #(sessionId), challenge_response: #(challengeResponse), email: '<email>' }
    When method post
    Then status 400

    Examples:
      | nonce | email          | password |
      | 1     | test@test.com  | Test1234 |
      | 2     | test1@test.com | Test1234 |

  Scenario Outline: Get rejected when providing wrong email and/or password

    Given path 'login/challenge'
    And request { nonce: <nonce> }
    When method post
    Then status 200
    And match response == { session_id: #notnull, challenge: #number }
    * def challengeResponse = response.challenge - nonce
    * def sessionId = response.session_id

    Given path 'login/token'
    And request { session_id: #(sessionId), challenge_response: #(challengeResponse), email: '<email>',  password: '<password>' }
    When method post
    Then status 401

    Examples:
      | nonce | email             | password        |
      | 1     | invalid@email.com | invalidPassword |
      | 2     | invalid@email.com | Test1234        |
      | 3     | test@test.com     | invalidPassword |
