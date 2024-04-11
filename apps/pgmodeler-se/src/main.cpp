/*
# PostgreSQL Database Modeler (pgModeler)
#
# Copyright 2006-2024 - Raphael Araújo e Silva <raphael@pgmodeler.io>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also, you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/

#include "application.h"
#include <QTranslator>
#include "schemaeditorform.h"
#include "pgmodelerapp.h"
#include "exception.h"
#include "enumtype.h"

int main(int argc, char **argv)
{
	try
	{
		GlobalAttributes::init(argv[0], true);
		PgModelerApp app(argc,argv);
		QStringList args = app.arguments();
		SchemaEditorForm syntaxchk;

		app.loadTranslations(QLocale::system().name(), false);

		args.pop_front();
		syntaxchk.loadFiles(args);
		syntaxchk.showMaximized();
		app.exec();

		return 0;
	}
	catch(Exception &e)
	{
		QTextStream out(stdout);
		out << e.getExceptionsText();
		return enum_t(e.getErrorCode());
	}
}
