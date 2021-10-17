#include "include/client/dummy_oidc_client.hpp"

OidcIdToken DummyOidcClient::get_token(const Credentials& credentials)
{
    return OidcIdToken("some-token", "Dummy");
}
