import logging
import threading
import time

threads = list()
cnt = 0

def thread_function(name):
    logging.info(f"Thread {name}: inizio")  #stampa
    time.sleep(2)   #mette in pausa il thread per 2 secondi
    logging.info(f"Thread {name}: fine")    #ultima stampa


    # 0 2 

def main():

    format = "%(asctime)s: %(message)s"
    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")

    cnt = 0

    for index in range (5):
        logging.info(f"Main     :  creo e faccio partire il thread {index}.")
        x = threading.Thread(target=thread_function, args = (index,))   #crea thread
        threads.append(x)
        if cnt <= 1:
            if index % 2 == 0:
                x.start()
                cnt = cnt + 1

    cnt = 1
    index = 0
    nFilosofi = 5

    while():

        if cnt == (nFilosofi - cnt) - index:
            threads[cnt+2].start()

        if cnt == (nFilosofi - cnt) - index:
            threads[cnt].start()
            threads[cnt + 2].start()
            
            cnt = cnt + 1

        if cnt == 1:
            threads[cnt].join
            threads[cnt + 2].start()
            threads[cnt + 2].start()
            

            cnt = cnt + 1

        if cnt < nFilosofi:
            cnt = 0
        index = index + 1

# 0 2 | 1 3 | 4 | 1 3 | 0 2 | 

if(__name__ == "__main__"):
    main()