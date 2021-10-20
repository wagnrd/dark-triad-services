function fn() {
    var env = java.lang.System.getenv('ENV');

    var config = {
        baseUrl: 'http://localhost:8080',
        loginBaseUrl: 'https://dark-triad-login-service.herokuapp.com',
        apiKey: ''
    };

    if (env === 'prod') {
        config.baseUrl = 'https://dark-triad-db.herokuapp.com';
        config.apiKey = java.lang.System.getenv('API_KEY');
    }

    return config;
}