function fn() {
    var env = java.lang.System.getenv('ENV');

    var config = {
        baseUrl: 'http://localhost:8081',
    };

    if (env === 'prod') {
        config.baseUrl = 'https://dark-triad-login-service.herokuapp.com';
    }

    return config;
}