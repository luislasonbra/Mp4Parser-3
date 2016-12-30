/*
 * Copyright (C) 2016 KhoaTran Programmer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "SMHDAtom.h"

static ErrInfo createDataFromFile(Atom* me, FileReader* fileReader)
{
	ErrInfo err = NoError;
	SmhdAtom* myself;

	myself = (SmhdAtom*)me;
	CAL_DATASIZE(myself)

	//read Version
	READ_BYTE(fileReader, myself, myself->version)

	//read Flags
	READ_BYTES(fileReader, myself, myself->flags, 3)

	//read balance
	READ_2BYTES(fileReader, myself, myself->balance)

	//read reserved
	READ_2BYTES(fileReader, myself, myself->reserved)

	return err;
}

static void destroy(Atom* me)
{
	SmhdAtom* myself;
	myself = (SmhdAtom*)me;

	FREE_FULLATOM(myself);
	free(myself);
}

ErrInfo CreateSmhdAtom(Atom** me, uint size, uint type)
{
	ErrInfo err = NoError;
	SmhdAtom* myself;

	myself = (SmhdAtom*) malloc(sizeof(SmhdAtom));
	SET_BASEATOM(myself);
	*me = (Atom*)myself;
	return err;
}
