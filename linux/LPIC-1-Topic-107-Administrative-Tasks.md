## LPIC-1 Topic 107: Administrative Tasks

### /etc/passwd
``
username:x:UID:GID:comment:home_directory:shell
``

### /etc/shadow
``
username:password:lastchanged:minage:maxage:warn:inactive:expire:reserved
``

- `!` im Passwortfeld: Passwort deaktiviert, aber Konto aktiv (z. B. für `su` oder SSH).
- `*` im Passwortfeld: Konto vollständig gesperrt, keine Anmeldung möglich.
- `john:!$hash:...` `john` ist gesperrt. Admin kann mit `sudo su - john` zu `john`wechseln.

### /etc/group
``
groupname:password:GID:members
``
- `password` Das `password`-Feld ist ein Relikt aus älteren UNIX-Systemen und wird auf modernen Linux-Distributionen wie Ubuntu praktisch nie verwendet. Siehe auch `/etc/gshadow`

#### Note
Die Dateien `/etc/passwd`, `/etc/shadow`, `/etc/group` und `/etc/gshadow` mit dem Postfix `-` sind Sicherungskopien der jeweiligen Datei.

### /etc/skel/

Das Verzeichnis `/etc/skel/` enthält Vorlagen für Dateien und Verzeichnisse, die in das Heimatverzeichnis eines neuen Benutzers kopiert werden, wenn dieser mit `useradd -m` erstellt wird.

##
### chage
Verwaltung der Passwort-Aging-Informationen eines Benutzers.

- `-l`: Zeigt Passwort-Aging-Informationen.
- `-m`: Mindestalter eines Passworts (in Tagen).
- `-M`: Maximales Alter eines Passworts (in Tagen).
- `-W`: Warnzeitraum vor Ablauf (in Tagen).
- `-E`: Setzt das Ablaufdatum des Kontos (Datum im Format `YYYY-MM-DD` oder `-1` für "niemals").

### getent
Abfrage von Systemdatenbanken wie `passwd`, `shadow`, `group`, `hosts` und `services`. Die Datenquellen werden durch die Konfigurationsdatei `/etc/nsswitch.conf` definiert und können aus lokalen Dateien oder externen Quellen (z. B. LDAP) stammen.

``getent database [key]``

### TODO
