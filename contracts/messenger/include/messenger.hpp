#include <eosio/eosio.hpp>

class [[eosio::contract]] messenger : public eosio::contract {
public:
	using eosio::contract::contract;

public:
	[[eosio::action]]
	void send(const eosio::name &from, const std::string &text);

	[[eosio::action]]
	void remove(const eosio::name &from, const std::uint64_t &id);

	[[eosio::action]]
	void edit(const eosio::name &from, const std::uint64_t &id, const std::string &text);

	[[eosio::action]]
	void clear(const eosio::name &from);

public:
	struct [[eosio::table]] message {
		std::uint64_t id;
		std::string text;
		std::uint64_t primary_key() const { return id; }
	};
	using messages = eosio::multi_index<eosio::name("messages"), message>;
};
