//	client et server
//	no memory leaks
//	variable globale possible pour client et server
//	PID
// client takes 2 params, PID of the serv and string
//	serv should be able to take multilple strings from multiple clients
//	UNIX signals
//	SIGUSR1 and SIGUSR2
//	BONUS: server confirms msg received by sending a signal to the client and UNICODE support


//	SERVER : pid_t getpid(void)
//	CLIENT : kill(pid_t pid, int sig)
//	use cmd 'top' to see all the processes active
// sigaction()
