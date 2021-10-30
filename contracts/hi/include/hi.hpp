#pragma once

#include <eosio/eosio.hpp>

class [[eosio::contract]] hi : public eosio::contract {
public:
	using eosio::contract::contract;

public:
	[[eosio::action]]
	void message(const eosio::name &from);
};
