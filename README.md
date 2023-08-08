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

1. Repository klonen: Klone das Repository auf deinen Computer.

2. MySQL installieren und Datenbank importieren: Installiere MySQL auf deinem System und importiere die Datenbank "werwirdmillionaer.sql" aus dem Ordner "Datenbank".

3. Qt installieren: Installiere das Qt-Framework. Wähle bei der Komponentenauswahl Folgendes aus:

- In "Qt 6.6.0-beta2": Wähle "MSVC 2019 64-bit" und "MinGW 11.2.0 64-bit".
- Unter "Zusätzliche Komponenten": Wähle "Qt 5-Kompatibilitätsmodul", "Qt Shader Tools" und "Qt Multimedia".
- In "Entwicklungs- und Designwerkzeuge": Wähle "Qt Creator 11.0.1", "Qt Creator 11.0.1 CDB Debugger Support", "MinGW 11.2.0 64-bit", "QT Installer Framework 4.6", "CMake 3.42.2" und "Ninja 1.10.2".

4. MySQL Connector/C installieren: Lade den "MySQL Connector/C" von folgendem Link herunter: https://downloads.mysql.com/archives/c-c/.

5. MySQL Connector/ODBC installieren: Lade "Connector/ODBC 8.1.0" von folgendem Link herunter: https://dev.mysql.com/downloads/connector/odbc/.

6. ODBC-Datenquelle einrichten: Öffne die "ODBC-Datenquelle (64-Bit)" und füge den "MySQL ODBC 8.1 Unicode Driver" hinzu. Gib deinen Host, Benutzernamen, Passwort und die Datenbank "werwirdmillionaer" ein.

7. Projekt ausführen: Jetzt kannst du das Projekt einfach ausführen und das Spiel genießen!

- Hinweis: Bitte stelle sicher, dass du alle Abhängigkeiten und Einstellungen gemäß den Anweisungen korrekt installierst, um das Spiel reibungslos nutzen zu können. Viel Spaß beim Spielen von "Wer wird Millionär"!

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
