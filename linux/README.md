### Zusammenfassung der wichtigsten Parameter:

| Parameter | Beschreibung |
|-----------|--------------|
| `$0`      | Name des Skripts/Befehls |
| `$1` bis `${n}` | Positionsparameter (Argumente) |
| `$#`      | Anzahl der übergebenen Argumente |
| `$@`      | Alle Argumente als separate Wörter |
| `$*`      | Alle Argumente als ein einziges Wort |
| `$?`      | Rückgabewert des letzten Befehls |
| `$$`      | Prozess-ID des aktuellen Skripts |
| `$!`      | Prozess-ID des zuletzt in den Hintergrund gesetzten Befehls |
| `$-`      | Aktuelle Shell-Optionen |
| `$IFS`    | Interner Feldtrennzeichen (Internal Field Separator) |

### Bash Parametererweiterung und -manipulation

| Syntax                         | Beschreibung |
|--------------------------------|--------------|
| `${var}`                       | Wert der Variable `var` (Standard). |
| `${var:-word}`                 | Wert von `var`, oder `word`, wenn `var` nicht gesetzt ist. |
| `${var:=word}`                 | Wert von `var`, oder setze `var` auf `word`, wenn `var` nicht gesetzt ist. |
| `${var:+word}`                 | `word`, wenn `var` gesetzt ist, ansonsten leer. |
| `${var:?message}`              | Gibt den Wert von `var` zurück, oder beendet das Skript mit `message`, wenn `var` nicht gesetzt ist. |
| `${var:offset}`                | Schneidet `var` ab dem Offset (nullbasiert) ab. |
| `${var:offset:length}`         | Schneidet `var` ab dem Offset ab und nimmt `length` Zeichen. |
| `${#var}`                      | Länge des Inhalts von `var`. |
| `${var#pattern}`               | Entfernt das kürzeste Präfix, das `pattern` entspricht, von `var`. |
| `${var##pattern}`              | Entfernt das längste Präfix, das `pattern` entspricht, von `var`. |
| `${var%pattern}`               | Entfernt das kürzeste Suffix, das `pattern` entspricht, von `var`. |
| `${var%%pattern}`              | Entfernt das längste Suffix, das `pattern` entspricht, von `var`. |
| `${var/pattern/replacement}`   | Ersetzt das erste Vorkommen von `pattern` in `var` durch `replacement`. |
| `${var//pattern/replacement}`  | Ersetzt alle Vorkommen von `pattern` in `var` durch `replacement`. |
| `${var/#pattern/replacement}`  | Ersetzt `pattern` durch `replacement` nur, wenn `pattern` am Anfang von `var` steht. |
| `${var/%pattern/replacement}`  | Ersetzt `pattern` durch `replacement` nur, wenn `pattern` am Ende von `var` steht. |
| `${!varprefix*}`               | Erweitert zu allen Variablen, die mit `varprefix` beginnen. |
| `${!varprefix@}`               | Wie `${!varprefix*}`, aber jede Variable einzeln zitiert. |
| `${var^}`                      | Wandelt den ersten Buchstaben von `var` in Großbuchstaben um. |
| `${var^^}`                     | Wandelt alle Buchstaben von `var` in Großbuchstaben um. |
| `${var,}`                      | Wandelt den ersten Buchstaben von `var` in Kleinbuchstaben um. |
| `${var,,}`                     | Wandelt alle Buchstaben von `var` in Kleinbuchstaben um. |
| `${var@Q}`                     | Quotiert den Wert von `var` so, dass er als Literal verwendet werden kann. |
