// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017 The MQX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("22579c2fed20fb0bb6b7a1c22f0a19b3449038d8844dfa3da05a2cf082514791"))
    (25, uint256("00000a34c1f35ca26f78591b20226a8e89c0101a03e6ece49c41475eb6948db3"))
    (49, uint256("000004e8d418827a9ee34f2c3e34087cf0a97c4acfc35ea69d21fd3068c19a5b"))
    (149, uint256("688690b365ea28e49c552b2f4208820bf6c9032a6ccc2690235701df17ac8e26"))
    (199, uint256("37a6cc65ec8d0804ba2913f62daedc0f5b483ae7a54ac3c7b94468134e34fa12"))
    (299, uint256("5f0531689c62294088363fdbb7977006ccb565aa3c192536d0d696747be68bef"))
    (399, uint256("0d2729c920923e7e8b35c882cbab12b10a581f27fbfd18176fd0db897cd4e88a"))
    (499, uint256("51f2d6632365a6da3c4ce520e088588fd09d57f2dda3e7ccff08ef2de43a2aa8"))
    (749, uint256("8511a10c1304ce17419c80b50a21f40a951d8ecc5fa4a807bbf241f7281f5c00"))
    (999, uint256("e28bd345d8dd12c0cf2265ce351f8e2976c85fd129a8f13a9aeafa0f82a73152"))
    (1249, uint256("1499cf760f8f29a6643286fb737728e0d7d2f9698c2c70e7cac2c470a1da314e"))
    (2007, uint256("3b95ff2ccaa45bbaf993f777c615592e475b5924d1a5d034f7dc4ebf892920d9"))
    (2499, uint256("5abb5f34e3b672b21d6d9b0a53ce21b5bfa01e73f55fab36a4c08483d981233d"))
    (2999, uint256("7b7f6370d5725c2fdd9c50efcd9cd5ce970c4b6e12da4ee2b7ba478f2b725baf"));
//    (3999, uint256("Hash"));
//    (4999, uint256("Hash"));
//    (5999, uint256("Hash"));
//    (6999, uint256("Hash"));
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1549152001, // * UNIX timestamp of last checkpoint block
    0,          // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    1000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1549152003,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1549152005,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        pchMessageStart[0] = 0xab;
        pchMessageStart[1] = 0xb6;
        pchMessageStart[2] = 0xfb;
        pchMessageStart[3] = 0x3c;
	vAlertPubKey = ParseHex("04ccc726f34c0ce24c972697b8fb2a01704eaa074467664929e9446a7bc17301ab7593f9d253b0ffffdb119c7b7fdc74bca3752bc9b09ddc74439ab50fe523c1ab");
        nDefaultPort = 58881;
        bnProofOfWorkLimit = ~uint256(0) >> 20;
        nSubsidyHalvingInterval = 2100000;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60;
        nTargetSpacingSlowLaunch = 1 * 60;
        nTargetSpacing = 1 * 60;
        nMaturity = 10;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 11000000 * COIN;

        nLastPOWBlock = 50;
        nModifierUpdateBlock = 999999999;
        nZerocoinStartHeight = 1051200;
        nAccumulatorStartHeight = 1;
        nZerocoinStartTime = 1549152001;
        nBlockEnforceSerialRange = 1;
        nBlockRecalculateAccumulators = ~1;
        nBlockFirstFraudulent = ~1;
        nBlockLastGoodCheckpoint = ~1;

	const char* pszTimestamp = "Land in zicht: een nieuw stukje Amsterdam verrijst in het IJ - MQX 20181116";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 1 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("044dbead02858c3618ee11253aee4512023752c1947f5b3651530a4d2cb0647d9a384b7094aa096b42bdd8da0ba20eff4f08c28507218205706a93076bc3c7d6d1") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1549152001;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 0;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("22579c2fed20fb0bb6b7a1c22f0a19b3449038d8844dfa3da05a2cf082514791"));
        assert(genesis.hashMerkleRoot == uint256("3c9165f9680fb0a0c8aa9be5c47f908e8986f5b4026e3a0b91780cc03af12184"));

        vSeeds.push_back(CDNSSeedData("server_1", "155.138.129.116"));
        vSeeds.push_back(CDNSSeedData("server_2", "34.73.9.231"));
        vSeeds.push_back(CDNSSeedData("server_3", "35.230.124.180"));
        vSeeds.push_back(CDNSSeedData("server_4", "104.196.208.247"));    

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 50);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 38);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 140);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x24)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x25)(0x21)(0x2B).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x90)(0x00)(0x32)(0x77).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
	strSporkKey = "04b4d60ddd8e03d6818ee9e9a1d834b94f864b5dbe1ce307ffeb546bd9573eacc4bd102afdcdd1f198bb4de8e7d2a3a4b8c9a1e33d4b1714051e50333573b129c7";
        strObfuscationPoolDummyAddress = "MKUWcAC6bH2yKb4SJnphFbyucrikfAt7mG";
        nStartMasternodePayments = 1549152001;

        zerocoinModulus = "25704721447193749820274651483865089628519739713778509712011072192578487693368476017697535832210276619911317289700028182029915932145116534902269387920678324625808043410410707877250857718089470444847194821752051821114301754239826024254898189397753818776708031525333797924168703101713189194116595790366210850082652432165353889442701554127334989336166937952397532637338506438981674108794037015331461879761959442656225883753036747627406499188027486071678731685195621836884076931843084742726199851857344924647989053491068726486274112711534149964648434978041325332076151433435806217526729799725956079413487948407929577350862535441529434841827324767930253844662824255347094122129130784513013998246424975275668883161651246221798746252097089000957";
	nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * ZCENT;    //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20;    //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100;        //full security level for accumulators
        nZerocoinHeaderVersion = 4;         //Block headers must be this version once zerocoin is active
        nBudget_Fee_Confirmations = 6;      // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0xfb;
        pchMessageStart[1] = 0xba;
        pchMessageStart[2] = 0xab;
        pchMessageStart[3] = 0x76;
        vAlertPubKey = ParseHex("04c389c1b9d5a393d52380ebb4e2fe6bd12e1b3e8461f3817b9063ab9924441c76747cd6561dc30429880cce5abe822e2e51dd0e4cab7f3894b6e2cca57c07dda7");
        nDefaultPort = 58883;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60;           // MirQuiX: 1 day
        nTargetSpacing = 1 * 60;            // MirQuiX: 1 minute
        nLastPOWBlock = 50;
        nMaturity = 1;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 999999999;
        nMaxMoneyOut = 11000000 * COIN;
        nZerocoinStartHeight = 200;
        nZerocoinStartTime = 1549152003; 
        nBlockEnforceSerialRange = 1;       //Enforce serial range starting this block
        nBlockRecalculateAccumulators = ~1; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = ~1;         //First block that bad serials emerged
        nBlockLastGoodCheckpoint = ~1;      //Last valid accumulator checkpoint

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1549152003;
	hashGenesisBlock = genesis.GetHash();

        vFixedSeeds.clear();                //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();                     //! Testnet mode doesn't have any DNS seeds.

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet MirQuiX addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet MirQuiX script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x80)(0x61)(0xa0)(0x3a).convert_to_container<std::vector<unsigned char> >();        // Testnet MirQuiX BIP32 pubkeys start with 'RKVD'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x37)(0x3a)(0x80)(0x58).convert_to_container<std::vector<unsigned char> >();        // Testnet MirQuiX BIP32 prvkeys start with 'PDRK'
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();        // Testnet MirQuiX BIP44 coin type is '1' (All coin's testnet default)

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04b99459180b533d0ce064852d1cfc1cb840732ad6733e036b469455d564d4a8b3679e3fda182431ba6109ae14b9815095e52f8dacf260913cc219e89bf5c7873a";
        strObfuscationPoolDummyAddress = "xp87cG8UEQgzs1Bk67Yk884C7pnQfAeo7q";
        nStartMasternodePayments = 1549152003;
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xcf;
        pchMessageStart[1] = 0xab;
        pchMessageStart[2] = 0x19;
        pchMessageStart[3] = 0x69;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // MirQuiX: 1 day
        nTargetSpacing = 1 * 60;        // MirQuiX:: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1549152005; 
        genesis.nBits = 0x1e0ffff0;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 58885;

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Regtest mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 58887;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};

static CChainParams* pCurrentParams = 0;

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
