#pragma once

#include <eosio/eosio.hpp>

class [[eosio::contract("contract")]] contract : public eosio::contract {
public:
	using eosio::contract::contract;

public:
	[[eosio::action("hi")]] void hi(eosio::name user);
};
