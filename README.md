# PR1-Altklausuren

Dieses Repository enthält Lösungen für Altklausursaufgaben mit allen zusätzlichen Funktionen.

Beachten Sie, dass verschiedene Methoden auf einfachere Weise implementiert werden können, indem die gesamte C++ - STL genutzt wird. Da in der Prüfung jedoch nur die angegebenen Header-Dateien verwendet werden können, werden alle Lösungen mithilfe der folgenden Header erstellt:

```
#include <iostream>
#include <string>
#include <vector>
```

Beachten Sie auch, dass die Datei main.cpp vom Ersteller der Prüfung vorab geschrieben wurde. Es enthält Testcode sowie die erwartete Ausgabe in den Kommentaren.

Die Richtigkeit der Lösungen wird überprüft, indem die Ausgabe und die erwartete Ausgabe mit dem folgenden Online-Tool verglichen werden: https://www.diffchecker.com/

## Building mit CMake

Sie müssen CMake installiert haben, um die folgenden Schritte ausführen zu können. ([Install CMake](https://cmake.org/install/))

Führen Sie die folgenden Schritte aus, um eine ausführbare Datei für eine der Übungen zu erstellen und auszuführen (Airport in diesem Beispiel):

```bash
git clone https://github.com/Peti0401/pr1-altklausuren.git
cd pr1-altklausuren
cd Airport
mkdir cmake-build
cmake -B cmake-build .
make --directory=cmake-build
cmake-build/Airport
```
