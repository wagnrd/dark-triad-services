@ignore
Feature: Delete all characters

  Background:
    * url baseUrl
    * def login = callonce read('../../utils/login.feature') { email: 'test1@test.com', password: 'Test1234' }
    * configure headers = { Authorization: #(login.authorization) }

  Scenario: Delete all characters for a given User ID

    Given path 'protected_api/characters'
    When method delete
    Then status 204