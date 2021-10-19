#include <contract.hpp>

void contract::hi(eosio::name user) {
	eosio::print("Hi ", user);
}
