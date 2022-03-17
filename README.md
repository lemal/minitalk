# minitalk
21 school project. UNIX signals, communication. Final in "wow"
The indended logic was for the client process to pause until a confirming signal comes from the server. The issue is that it works without the "pause",
and will break if the process receives a SIGUSR2 from anywhere. This is because the client will not check for teh pid of the process that sent the 
signal to it.
