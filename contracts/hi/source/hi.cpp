#include <hi.hpp>

void hi::message(const eosio::name &from) {
	eosio::print("Hi ", from);
}
