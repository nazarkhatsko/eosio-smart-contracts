#include <random.hpp>

void random::trying(const eosio::name &from) {
	eosio::require_auth(from);

	attempts att(get_self(), get_self().value);
	std::uint64_t id = att.available_primary_key();
	att.emplace(from, [&](auto &item) {
		item.id = id;
		item.user = from;
	});

	uint64_t signing_value = id + 4;
	for (uint8_t i = 1; i < 9; i++) {
		signing_value *= signing_value;
	}

	eosio::action(
		{get_self(), eosio::name("active")},
		eosio::name("orng.wax"),
		eosio::name("requestrand"),
		std::tuple(id, signing_value, get_self())
	).send();
}

void random::receiverand(const std::uint64_t &customer_id, const eosio::checksum256 &random_value) {
	eosio::require_auth(eosio::name("orng.wax"));

	uint64_t max_value = 100;
	auto byte_array = random_value.extract_as_byte_array();
	uint64_t random_int = 0;
	for (int i = 0; i < 8; i++) {
		random_int <<= 8;
		random_int |= (uint64_t)byte_array[i];
	}

	uint64_t rand_num = random_int % max_value;

	attempts att(get_self(), get_self().value);
	uint64_t id = att.available_primary_key();
	auto itr = att.find(id);
	if (itr != att.end()) {
		att.modify(itr, get_self(), [&](auto &item) {
			item.status = (rand_num < 20 ? "+" : "-");
		});
	}
}

void random::clear() {
	attempts att(get_self(), get_self().value);
	while (att.begin() != att.end()) {
		att.erase(att.begin());
	}
}
