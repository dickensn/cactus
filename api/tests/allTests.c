/*
 * Copyright (C) 2009-2011 by Benedict Paten (benedictpaten@gmail.com)
 *
 * Released under the MIT license, see LICENSE.txt
 */

#include "cactusGlobalsPrivate.h"

CuSuite *cactusGroupTestSuite();
CuSuite *cactusSegmentTestSuite();
CuSuite *cactusBlockTestSuite();
CuSuite *cactusChainTestSuite();
CuSuite *cactusCapTestSuite();
CuSuite *cactusEndTestSuite();
CuSuite *cactusEventTestSuite();
CuSuite *cactusEventTreeTestSuite();
CuSuite *cactusLinkTestSuite();
CuSuite *cactusMetaSequenceTestSuite();
CuSuite *cactusDiskTestSuite();
CuSuite *cactusMiscTestSuite();
CuSuite *cactusFlowerTestSuite();
CuSuite *cactusFaceTestSuite();
CuSuite *cactusFaceEndTestSuite();
CuSuite *cactusSequenceTestSuite();
CuSuite *cactusSerialisationTestSuite();
CuSuite *cactusFlowerWriterTestSuite();


int cactusAPIRunAllTests(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();
	CuSuiteAddSuite(suite, cactusEventTestSuite());
	CuSuiteAddSuite(suite, cactusGroupTestSuite());
	CuSuiteAddSuite(suite, cactusSegmentTestSuite());
	CuSuiteAddSuite(suite, cactusBlockTestSuite());
	CuSuiteAddSuite(suite, cactusChainTestSuite());
	CuSuiteAddSuite(suite, cactusCapTestSuite());
	CuSuiteAddSuite(suite, cactusEndTestSuite());
	CuSuiteAddSuite(suite, cactusEventTreeTestSuite());
	CuSuiteAddSuite(suite, cactusLinkTestSuite());
	CuSuiteAddSuite(suite, cactusMetaSequenceTestSuite());
	CuSuiteAddSuite(suite, cactusDiskTestSuite());
	CuSuiteAddSuite(suite, cactusMiscTestSuite());
	CuSuiteAddSuite(suite, cactusFlowerTestSuite());
	CuSuiteAddSuite(suite, cactusFaceTestSuite());
	CuSuiteAddSuite(suite, cactusFaceEndTestSuite());
	CuSuiteAddSuite(suite, cactusSequenceTestSuite());
	CuSuiteAddSuite(suite, cactusSerialisationTestSuite());
	CuSuiteAddSuite(suite, cactusFlowerWriterTestSuite());
	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
	int i= suite->failCount > 0;
	CuSuiteDelete(suite);
	CuStringDelete(output);
	return i;
}

int main(int argc, char *argv[]) {
    if(argc == 2) {
            st_setLogLevelFromString(argv[1]);
        }
	int i = cactusAPIRunAllTests();
	//while(1);
	return i;
}
