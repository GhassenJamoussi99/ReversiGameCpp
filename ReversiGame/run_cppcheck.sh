#!/bin/sh

echo "running cppcheck..."
echo "generate xml file..."
cppcheck --xml --enable=all --suppress=missingIncludeSystem -itests -Iinclude/game -Iinclude/players -Iinclude/ui   -Iexternal/ ./src/players ./src/ui  ./src/game 2>tests/static/cppcheck/report_reversi.xml
echo "generate log file..."
cppcheck --enable=all --suppress=missingIncludeSystem -itests -Iinclude/game -Iinclude/players -Iinclude/ui   -Iexternal/ ./src/players ./src/ui  ./src/game 2>tests/static/cppcheck/report_reversi.log

echo "generate html report from the xml file..."
cppcheck-htmlreport  --file=tests/static/cppcheck/report_reversi.xml --title=LibreOffice --report-dir=tests/static/cppcheck/cppcheck_reports --source-dir=.
