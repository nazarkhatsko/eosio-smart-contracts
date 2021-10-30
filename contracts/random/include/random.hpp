#include <eosio/eosio.hpp>

class [[eosio::contract]] random : public eosio::contract {
public:
	using eosio::contract::contract;

public:
	[[eosio::action]]
	void trying(const eosio::name &from);

	[[eosio::action]]
	void receiverand(const std::uint64_t &customer_id, const eosio::checksum256 &random_value);

	[[eosio::action]]
	void clear();

private:
	struct [[eosio::table]] attempt {
		std::uint64_t id;
		eosio::name user;
		std::string status;
		std::uint64_t primary_key() const { return id; }
	};

	using attempts = eosio::multi_index<eosio::name("attempts"), attempt>;
};
