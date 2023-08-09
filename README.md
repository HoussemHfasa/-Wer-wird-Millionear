# Wer wird Millionear

## Einführung

Wer wird Millionear" ist ein Quizspiel, bei dem Spieler ihr Wissen in verschiedenen Kategorien testen können. Die Spieler können vor dem Spiel den Schwierigkeitsgrad und die Kategorie auswählen. Das Spiel hat ein Lebenssystem, bei dem die Spieler bei jeder falschen Antwort ein Leben verlieren. Es gibt auch drei Joker, die den Spielern helfen: 50/50, Frage das Publikum und Frage einen Freund. Die Spiellogik kümmert sich um das Spielmanagement, das Lebenstracking, die Implementierung der Joker und die Integration mit UI und Datenbank.

## Funktionen

- Anmeldung nur mit Nickname
- Auswahl von Schwierigkeitsgrad
- Auswahl der Kategorie
- Quizfragen beantworten
- Lebenssystem mit Verlust eines Lebens pro falscher Antwort
- Drei Joker: 50/50, Frage das Publikum, Frage einen Freund
- Einstellungen verwalten
- Speichern des Fortschritts
- Anzeige der Spielanleitung
- Punktetracking und Highscore-Liste

## Technischer Stack

- C++
- Qt für das Frontend
- MySQL für die Datenbank

## Systemanforderungen

- Qt Framework
- C++ Compiler
- MySQL

## Installation

1. To clone the repository, open your command line interface and navigate to the desired directory where you want to clone the repository. Then use the following command:

   ```
   git clone <repository_url>
   ```

   Replace `<repository_url>` with the actual URL of the repository.

2. Install MySQL on your system by downloading the appropriate installer for your operating system from the official MySQL website. Follow the installation instructions provided by the installer.

   Once MySQL is installed, open a command line interface and navigate to the directory where MySQL is installed. Locate the `mysql` command-line tool and execute it.

   To import the "werwirdmillionaer.sql" database, use the following command:

   ```
   mysql -u <username> -p <database_name> < <path_to_sql_file>
   ```

   Replace `<username>` with your MySQL username, `<database_name>` with the desired name for the database, and `<path_to_sql_file>` with the path to the "werwirdmillionaer.sql" file.

3. To install the Qt framework, visit the Qt website and download the installer for your operating system. Run the installer and follow the on-screen instructions.

   During the installation, make sure to select the following components:

   - In "Qt 6.6.0-beta2": Choose "MSVC 2019 64-bit" and "MinGW 11.2.0 64-bit".
   - Under "Additional Components": Select "Qt 5 Compatibility Module", "Qt Shader Tools", and "Qt Multimedia".
   - In "Development and Design Tools": Choose "Qt Creator 11.0.1", "Qt Creator 11.0.1 CDB Debugger Support", "MinGW 11.2.0 64-bit", "QT Installer Framework 4.6", "CMake 3.42.2", and "Ninja 1.10.2".

4. To install MySQL Connector/C, visit the following link: [MySQL Connector/C Archives](https://downloads.mysql.com/archives/c-c/). Download the desired version of MySQL Connector/C based on your operating system.

5. To install MySQL Connector/ODBC, visit the following link: [MySQL Connector/ODBC Downloads](https://dev.mysql.com/downloads/connector/odbc/). Download the "Connector/ODBC 8.1.0" version.

6. To set up the ODBC data source, open the "ODBC Data Source Administrator" application on your system. Add a new data source using the "MySQL ODBC 8.1 Unicode Driver". Provide the necessary details such as the host, username, password, and database name ("werwirdmillionaer").

7. After completing the previous steps, you can run the project and enjoy playing "Wer wird Millionär"! Make sure to create an `.env` file in each folder of the project and include the following content:

   ```
   DB_TYPE=QODBC
   DB_DRIVER={MySQL ODBC 8.1 Unicode Driver}
   DB_HOST=localhost
   DB_NAME=werwirdmillionaer
   DB_USER=Dein Benutzername
   DB_PASS=Dein Passwort.
   ```

   Adjust the values accordingly based on your MySQL configuration.

Note: Make sure to install all the dependencies and configure the settings correctly according to the instructions provided for a smooth experience with the game. Have fun playing "Wer wird Millionär"!

## Verwendung

Das Spiel startet auf der Hauptseite, wo der Schwierigkeitsgrad und die Kategorie ausgewählt werden können. Nach Drücken des Start-Buttons beginnt das Quiz. Bei jeder Frage können eventuell vorhandene Joker eingesetzt werden, bevor eine Antwort ausgewählt wird. Nach Beantwortung aller Fragen wird der Endbildschirm mit dem Ergebnis angezeigt.

## Lizenz

Copyright (c) 2023 HTW Berlin Vertiefung Programmierung (Rama Abazied, Yassin Sahnoun, Houssem Hfasa)

MIT-Lizenz

Hiermit wird jeder Person, die eine Kopie dieser Software und der zugehörigen Dokumentationsdateien (die "Software") erhält, die Erlaubnis erteilt, kostenlos und ohne Einschränkungen mit der Software zu handeln. Dies umfasst die Rechte zur Nutzung, zum Kopieren, Ändern, Zusammenführen, Veröffentlichen, Verteilen, Unterlizenzieren und/oder Verkaufen von Kopien der Software.

Die folgenden Bedingungen müssen erfüllt sein, um diese Erlaubnis zu erhalten:

Der oben genannte Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen Kopien oder wesentlichen Teilen der Software enthalten sein.

DIE SOFTWARE WIRD "WIE SIE IST" UND OHNE JEGLICHE AUSDRÜCKLICHE ODER STILLSCHWEIGENDE GEWÄHRLEISTUNG BEREITGESTELLT. DIES BEINHALTET, ABER IST NICHT BESCHRÄNKT AUF, GEWÄHRLEISTUNGEN DER MARKTGÄNGIGKEIT, EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL SIND DIE URHEBER ODER URHEBERRECHTSINHABER HAFTBAR FÜR ANSPRÜCHE, SCHÄDEN ODER ANDERE VERBINDLICHKEITEN, OB IN EINER VERTRAGS- ODER HAFTUNGSKLAGE, EINER UNERLAUBTEN HANDLUNG ODER ANDERWEITIG, DIE SICH AUS, AUS ODER IN VERBINDUNG MIT DER SOFTWARE ODER DER NUTZUNG ODER ANDEREN HANDLUNGEN MIT DER SOFTWARE ERGEBEN.

Diese Software ist Open Source und wird unter der MIT-Lizenz vergeben.
