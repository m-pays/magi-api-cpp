#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <algorithm>
#include "main.cpp"

BOOST_AUTO_TEST_SUITE(MiningTests)

BOOST_AUTO_TEST_CASE(GetBestBlockHash) {

	MyFixture fx;
	std::string response;

	BOOST_REQUIRE_NO_THROW(response = fx.xmg.getbestblockhash());
	BOOST_REQUIRE(response.size() == 64);

	#ifdef VERBOSE
	std::cout << "=== getbestblockhash ===" << std::endl;
	std::cout << response << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(GetBlockHash) {

	MyFixture fx;
	std::string response;

	BOOST_REQUIRE_NO_THROW(response = fx.xmg.getblockhash(300000));
	BOOST_REQUIRE(response.size() == 64);

	#ifdef VERBOSE
	std::cout << "=== getblockhash ===" << std::endl;
	std::cout << response << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(GetBlockCount) {

	MyFixture fx;
	int response;

	BOOST_REQUIRE_NO_THROW(response = fx.xmg.getblockcount());
	BOOST_REQUIRE(response >= 300000);

	#ifdef VERBOSE
	std::cout << "=== getblockcount ===" << std::endl;
	std::cout << response << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(GetBlock) {

	MyFixture fx;
	blockinfo_t response;

	BOOST_REQUIRE_NO_THROW(response = fx.xmg.getblock("000000000000000082ccf8f1557c5d40b21edabb18d2d691cfbf87118bac7254"));
	BOOST_REQUIRE(response.height == 300000);

	#ifdef VERBOSE
	std::cout << "=== getblock (300000th block) ===" << std::endl;
	std::cout << "hash: " << response.hash << std::endl;
	std::cout << "confirmations: " << response.confirmations << std::endl;
	std::cout << "size: " << response.size << std::endl;
	std::cout << "height: " << response.height << std::endl;
	std::cout << "version: " << response.version << std::endl;
	std::cout << "merkleroot: " << response.merkleroot << std::endl;

	std::cout << "tx: " << std::endl;
	for(std::vector<std::string>::iterator it = response.tx.begin(); it != response.tx.end(); it++){
		std::cout << "  " << (*it) << std::endl;
	}

	std::cout << "time: " << response.time << std::endl;
	std::cout << "nonce: " << response.nonce << std::endl;
	std::cout << "bits: " << response.bits << std::endl;
	std::cout << "difficulty: " << response.difficulty << std::endl;
	std::cout << "chainwork: " << response.chainwork << std::endl;
	std::cout << "previousblockhash: " << response.previousblockhash << std::endl;
	std::cout << "nextblockhash: " << response.nextblockhash << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(GetGenerate) {

	MyFixture fx;
	bool response;

	BOOST_REQUIRE_NO_THROW(response = fx.xmg.getgenerate());
	BOOST_REQUIRE(response == true || response == false);

	#ifdef VERBOSE
	std::cout << "=== getgenerate ===" << std::endl;
	std::cout << response << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(SetGenerate) {

	MyFixture fx;

	BOOST_REQUIRE_NO_THROW(fx.xmg.setgenerate(true));
	BOOST_REQUIRE(fx.xmg.getgenerate() == true);

	BOOST_REQUIRE_NO_THROW(fx.xmg.setgenerate(false));
	BOOST_REQUIRE(fx.xmg.getgenerate() == false);
}



BOOST_AUTO_TEST_CASE(GetDifficulty) {

	MyFixture fx;
	double response;

	BOOST_REQUIRE_NO_THROW(response = fx.xmg.getdifficulty());
	BOOST_REQUIRE(response >= 10000000000);

	#ifdef VERBOSE
	std::cout << "=== getdifficulty ===" << std::endl;
	std::cout << response << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(GetHashesPerSec) {

	MyFixture fx;
	int response = -1;

	BOOST_REQUIRE_NO_THROW(response = fx.xmg.gethashespersec());
	BOOST_REQUIRE(response >= 0);

	#ifdef VERBOSE
	std::cout << "=== gethashespersec ===" << std::endl;
	std::cout << response << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(GetMiningInfo) {

	MyFixture fx;
	mininginfo_t response;

	BOOST_REQUIRE_NO_THROW(response = fx.xmg.getmininginfo());
	BOOST_REQUIRE(response.blocks >= 300000);

	#ifdef VERBOSE
	std::cout << "=== getmininginfo ===" << std::endl;
	std::cout << "blocks: " << response.blocks << std::endl;
	std::cout << "currentblocksize: " << response.currentblocksize << std::endl;
	std::cout << "currentblocktx: " << response.currentblocktx << std::endl;
	std::cout << "difficulty: " << response.difficulty << std::endl;
	std::cout << "errors: " << response.errors << std::endl;
	std::cout << "genproclimit: " << response.genproclimit << std::endl;
	std::cout << "networkhashps: " << response.networkhashps << std::endl;
	std::cout << "pooledtx: " << response.pooledtx << std::endl;
	std::cout << "testnet: " << response.testnet << std::endl;
	std::cout << "generate: " << response.generate << std::endl;
	std::cout << "hashespersec: " << response.hashespersec << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(GetWork) {

	MyFixture fx;

	std::string param =
			"000000020597ba1f0cd423b2a3abb0259a54ee5f783077a4ad45fb"
			"6200000218000000008348d1339e6797e2b15e9a3f2fb7da08768e"
			"99f02727e4227e02903e43a42b31511553101a051f3c0000000000"
			"000080000000000000000000000000000000000000000000000000"
			"0000000000000000000000000000000080020000";

	workdata_t response;
	bool response2;

	BOOST_REQUIRE_NO_THROW(response = fx.xmg.getwork());
	BOOST_REQUIRE(response.midstate.size() == 64);
	BOOST_REQUIRE(response.data.size() == 256);
	BOOST_REQUIRE(response.hash1.size() == 128);
	BOOST_REQUIRE(response.target.size() == 64);

	BOOST_REQUIRE_NO_THROW(response2 = fx.xmg.getwork(param));
	BOOST_REQUIRE(response2 == false);

	#ifdef VERBOSE
	std::cout << "=== getwork ===" << std::endl;
	std::cout << "midstate: " << response.midstate << std::endl;
	std::cout << "data: " << response.data << std::endl;
	std::cout << "hash: " << response.hash1 << std::endl;
	std::cout << "target: " << response.target << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_CASE(ListSinceBlock) {

	MyFixture fx;
	txsinceblock_t response;

	BOOST_REQUIRE_NO_THROW(response = fx.xmg.listsinceblock("", 1));

	#ifdef VERBOSE
	std::cout << "=== listsinceblock ===" << std::endl;
	for(std::vector<transactioninfo_t>::iterator it = response.transactions.begin(); it != response.transactions.end(); it++){
		transactioninfo_t tx = (*it);
		std::cout << "Account: " << tx.account << std::endl;
		std::cout << "Address: " << tx.address << std::endl;
		std::cout << "Category: " << tx.category << std::endl;
		std::cout << "Amount: " << tx.amount << std::endl;
		std::cout << "Confirmations: " << tx.confirmations << std::endl;
		std::cout << "Blockhash: " << tx.blockhash << std::endl;
		std::cout << "Blockindex: " << tx.blockindex << std::endl;
		std::cout << "Blocktime: " << tx.blocktime << std::endl;
		std::cout << "Txid: " << tx.txid << std::endl;
		std::cout << "Walletconflicts: " << std::endl;

		for(std::vector<std::string>::iterator it2 = tx.walletconflicts.begin(); it2 != tx.walletconflicts.end(); it2++){
			std::cout << "  " << (*it2) << std::endl;
		}

		std::cout << "Time: " << tx.time << std::endl;
		std::cout << "Timereceived: " << tx.timereceived << std::endl << std::endl;
	}
	std::cout << "lastblock: " << response.lastblock << std::endl << std::endl;
	#endif
}

BOOST_AUTO_TEST_SUITE_END()
