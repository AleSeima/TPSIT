import logging
import threading
import time

def thread_function(name):
    logging.info(f"Thread {name}: inizio")  #stampa
    time.sleep(2)   #mette in pausa il thread per 2 secondi
    logging.info(f"Thread {name}: fine")    #ultima stampa

if __name__ == "__main__":
    format = "%(asctime)s: %(message)s" #formato stringa dei messaggi
    logging.basicConfig(format = format, level=logging.INFO,datefmt="%H:%M:%S") #formato orario

threads = list()
for index in range (3):
    logging.info(f"Main     :  creo e faccio partire il thread {index}.")
    x = threading.Thread(target=thread_function, args = (index,))   #crea thread
    threads.append(x)
    x.start()

for index, thread in enumerate(threads):
    logging.info(f"Main     :  in attesa delo thread {index}.")
    thread.join
    logging.info(f"Main     :  thread {index} terminato")
