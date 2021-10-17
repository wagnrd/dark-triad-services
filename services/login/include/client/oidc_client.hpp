#ifndef DARK_TRIAD_LOGIN_SERVICE_OIDC_CLIENT_HPP
#define DARK_TRIAD_LOGIN_SERVICE_OIDC_CLIENT_HPP

template<class T>
class OidcClient: public Service<T> {
public:
    virtual OidcIdToken get_token(const Credentials& credentials) = 0;
};

#endif //DARK_TRIAD_LOGIN_SERVICE_OIDC_CLIENT_HPP
