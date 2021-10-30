#include <messenger.hpp>

void messenger::send(const eosio::name &from, const std::string &text) {
	eosio::require_auth(from);

	messages mess(get_self(), from.value);
	mess.emplace(get_self(), [&](auto &item) {
		item.id = mess.available_primary_key();
		item.text = text;
	});
}

void messenger::remove(const eosio::name &from, const std::uint64_t &id) {
	eosio::require_auth(from);

	messages mess(get_self(), from.value);
	auto itr = mess.find(id);
	eosio::check(itr != mess.end(), "id not found");
	mess.erase(itr);
}

void messenger::edit(const eosio::name &from, const std::uint64_t &id, const std::string &text) {
	eosio::require_auth(from);

	messages mess(get_self(), from.value);
	auto itr = mess.find(id);
	eosio::check(itr != mess.end(), "id not found");
	mess.modify(itr, from, [&](auto &item) {
		item.text = text;
	});
}

void messenger::clear(const eosio::name &from) {
	eosio::require_auth(from);
	
	messages mess(get_self(), from.value);
	while (mess.begin() != mess.end()) {
		mess.erase(mess.begin());
	}
}
