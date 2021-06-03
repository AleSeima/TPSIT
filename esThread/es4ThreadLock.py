import logging
import threading
import time

#FINISCO DI COPIARLO DA CLASSROOM

def thread_function(name):
    logging.info(f"Thread {name}: inizio")  #stampa
    time.sleep(2)   #mette in pausa il thread per 2 secondi
    logging.info(f"Thread {name}: fine")    #ultima stampa

def __init__(self):
    self.value = 0
    self.lock = threading.Lock()

def locked_update(self, name):
    logging.info(f"Thread {name} :  avvio dell'aggiornamento del DB")
    logging.debug(f"Thread {name}  :  aggiornamento del Lock")


class FakeDatabase:
    logging.info(f"Thread {name}  :  avvio dell'aggiornamento del DB")
    local_copy = self.value #copia il valore zero nela variab ile locale
    local_copy += 1
    time.sleep(2)   #mette in pausa il thread corrente
    self.value = local_copy #copia nel DB il valore incrementato nella variabile local_copy
    logging.info(f"Thread {name}  :  termine dell'aggiornamento del DB")


if __name__ == "__main__":
    format = "%(asctime)s: %(message)s" #formato stringa dei messaggi
    logging.basicConfig(format = format, level=logging.INFO,datefmt="%H:%M:%S") #formato orario

database = FakeDatabase()
threads = list()
logging.info(f"Valore iniziale del DB {database.value}.")
for index in range (3):
    logging.info(f"Main     :  creo e faccio partire il thread {index}.")
    x = threading.Thread(target=thread_function, args = (index,))
    threads.append(x)
    x.start()

for index, thread in enumerate(threads):
    logging.info(f"Main     :  in attesa delo thread {index}.")
    thread.join
    logging.info(f"Main     :  thread {index} terminato")