#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
#include "../../include/defs.h"
#include "../../include/checks.h"
#include "../../include/tables.h"
#include "../../include/position.h"
#include "../../include/tests/tests.h"
#include "../../include/tests/testboards.h"
#include "../../include/tests/test_bitboards.h"
#include "../../include/search.h"

using namespace std;

TestClass::TestClass() {
	testDefaultSetup();
	testPin1();
	testMateInOne1();
	testStartingStalemateWhite();
	testStartingStalemateBlack();
	testStartingCheckmateWhite();
	testStartingCheckmateBlack();
	testAnyLegalMoves1();
	testAnyLegalMoves2();
	testNoLegalMoves();
	testMateInTwo1();
	testMateInTwo2();
	testForcedStalemate1();
	testPromotion1();
	TestBitboards t;
}

void TestClass::testDefaultSetup() {
	S_BOARD board = createBitboards(defaultBoard);
	assert(board.wR == SQUARES[A1] | SQUARES[H1]);
	assert(board.wN == SQUARES[B1] | SQUARES[G1]);
	assert(board.wB == SQUARES[C1] | SQUARES[F1]);	
	assert(board.wQ == SQUARES[D1]);
	assert(board.wK == SQUARES[E1]);
	assert(board.wP == RANK2);
	assert(board.bR == SQUARES[A8] | SQUARES[H8]);
	assert(board.bN == SQUARES[B8] | SQUARES[G8]);
	assert(board.bB == SQUARES[C8] | SQUARES[F8]);
	assert(board.bQ == SQUARES[D8]);
	assert(board.bK == SQUARES[E8]);
	assert(board.bP == RANK7);
}

//Test that we can pin black's rook to his king and win the exchange
void TestClass::testPin1() {
	S_BOARD b = createBitboards(testPinBoard1);
	Position pos(b, WHITE);
	S_MOVE move = search(pos, 4);
	assert(move.evaluation == 0);
	assert(move.toSquare == C4);
}

void TestClass::testMateInOne1() {
	S_BOARD b = createBitboards(testMateInOneBoard1);
	Position pos(b, WHITE);
	S_MOVE move = search(pos, 2);
	assert(move.evaluation == 9999);
	assert(move.toSquare == H8);
}

void TestClass::testStartingStalemateWhite() {
	S_BOARD b = createBitboards(testStartingStalemateWhiteBoard);
	Position pos(b, WHITE);
	S_MOVE move = search(pos, 1);
	assert(move.evaluation == 0);
	assert(move.fromSquare == -1);
}

void TestClass::testStartingStalemateBlack() {
	S_BOARD b = createBitboards(testStartingStalemateBlackBoard);
	Position pos(b, BLACK);
	S_MOVE move = search(pos, 1);
	assert(move.evaluation == 0);
	assert(move.fromSquare == -1);
}

void TestClass::testStartingCheckmateWhite() {
	S_BOARD b = createBitboards(testStartingCheckmateWhiteBoard);
	Position pos(b, WHITE);
	S_MOVE move = search(pos, 1);
	assert(move.evaluation == -9999);
	assert(move.fromSquare == -1);
}

void TestClass::testStartingCheckmateBlack() {
	S_BOARD b = createBitboards(testStartingCheckmateBlackBoard);
	Position pos(b, BLACK);
	S_MOVE move = search(pos, 1);
	assert(move.evaluation == 9999);
	assert(move.fromSquare == -1);
}

void TestClass::testAnyLegalMoves1() {
	S_BOARD b = createBitboards(testAnyLegalMovesBoard1);
	Position pos(b, WHITE);
	assert(pos.anyLegalMoves() == true);
}

void TestClass::testAnyLegalMoves2() {
	S_BOARD b = createBitboards(testAnyLegalMovesBoard2);
	Position pos(b, WHITE);
	S_MOVE move = search(pos, 1);
	assert(move.evaluation == 3);
}

void TestClass::testNoLegalMoves() {
	S_BOARD b = createBitboards(testAnyLegalMovesBoard1);
	Position pos(b, BLACK);
	assert(pos.anyLegalMoves() == false);
}

void TestClass::testMateInTwo1() {
	S_BOARD b = createBitboards(testMateInTwoBoard1);
	Position pos(b, WHITE);
	S_MOVE move = search(pos, 3);
	assert(move.fromSquare == 38);
	assert(move.toSquare == 54);
	assert(move.evaluation == 9999);
}

void TestClass::testMateInTwo2() {
	S_BOARD b = createBitboards(testMateInTwoBoard2);
	Position pos(b, WHITE);
	S_MOVE move = search(pos, 3);
	assert(move.fromSquare == 15);
	assert(move.toSquare == 47);
	assert(move.evaluation == 9999);
}

void TestClass::testForcedStalemate1() {
	S_BOARD b = createBitboards(testForcedStalemateBoard1);
	Position pos(b, BLACK);
	S_MOVE move = search(pos, 4);
	assert(move.fromSquare == 50);
	assert(move.toSquare == 42);
	assert(move.evaluation == 0);
}

void TestClass::testPromotion1() {
	S_BOARD b = createBitboards(testPromotionBoard1);
	Position pos(b, WHITE);
	// S_MOVE move = search(pos, 1);
}




