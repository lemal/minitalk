# minitalk

The client process converts symbolic input into binary representations of each symbol and sends them over using SIGUSR1 and SIGUSR2. Server converts them back and writes them out (even UTF-8!)
_____________________________

Процесс-клиент посылает процессу-серверу двоичное предствление своего ввода, чтобы сервер их вывел в терминал.
