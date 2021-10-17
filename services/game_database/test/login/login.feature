@ignore
Feature: Login

  Background:
    * url loginBaseUrl

  Scenario: Get token for valid user credential

    Given path 'login/challenge'
    And request { nonce: 1234 }
    When method post
    Then status 200
    And match response == { session_id: #notnull, challenge: #number }
    * def challengeResponse = response.challenge -1234
    * def sessionId = response.session_id

    Given path 'login/token'
    And request { session_id: #(sessionId), challenge_response: #(challengeResponse), email: '#(email)', password: '#(password)' }
    When method post
    Then status 200
    And match response == { id_token: #string, token_type: #string }
    * def token = response.token_type + ' ' + response.id_token
