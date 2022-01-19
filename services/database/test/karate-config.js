function fn() {
    var env = java.lang.System.getenv('ENV');

    var config = {
        baseUrl: 'http://localhost:8080',
        loginBaseUrl: 'http://localhost:8081',
        apiKey: ''
    };

    if (env === 'prod') {
        config.baseUrl = 'https://dark-triad-database-service.herokuapp.com';
        config.loginBaseUrl: 'https://dark-triad-login-service.herokuapp.com',
        config.apiKey = java.lang.System.getenv('API_KEY');
    }

    return config;
}