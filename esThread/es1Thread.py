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

    logging.info("Main      : creo il thread")  #debug
    x = threading.Thread(target=thread_function, args=(1,), daemon=True)    #daemon=True fa terminare subito il programma senza farlo aspettare i due secondi che ci sarebbero senza il deamon, ovvero i due secondi di attesa erno dati per apsettare che il secondo Thread avviato finisse.
    logging.info("Main      : eseguo il thread")
    x.start() #avvio del thread x, biforcazione in due flussi, esecuzione sia funzione che righe successive
    logging.info("Main      : attendere che il thread finisce")
    x.join() #riusnisce la biforcazione che si era creata a riga 17, attende che il thread x termini. Si ferma, ferma il primo, attende che il secondo Thread finisce, e infine fa finire il primo
    logging.info("Main      : fine")

    #loggig registra semplici errori di script
    #time.sleep() mette in pausa di 2 secondi

    #Primo: Fa finire quello principale e dopo due secondi finisce il secondo
    #Secondo: fa terminare subito il programma senza farlo aspettare i due secondi che ci sarebbero senza il deamon, ovvero i due secondi di attesa erno dati per apsettare che il secondo Thread avviato finisse.
    #Terzo: attende che il thread x termini. Si ferma, ferma il primo, attende che il secondo Thread finisce, e infine fa finire il primo