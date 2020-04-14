class samochod:
    def __init__(self, marka, model, rocznik, pojemnosc, przebieg, typ_skrzyni_biegow): 
        self.marka = marka
        self.model = model
        self.rocznik = rocznik
        self.pojemnosc = pojemnosc
        self.przebieg = przebieg
        self.typ_skrzyni_biegow = typ_skrzyni_biegow
        
class operacje_na_samochodach(samochod):    
    def wczytaj(self):
        file = open("katalog.txt","r")
        samochody=[]
        for line in file:
            pole = line.split(" ")
            ma=pole[0]
            mo=pole[1]
            ro=int(pole[2])
            poj=int(pole[3])
            prz=int(pole[4])
            typ=pole[5].rstrip()
            samochody.append(samochod(ma,mo,ro,poj,prz,typ))
        file.close()
        return samochody
    def lista(self,samochody):
        i=1
        for obj in samochody:
            print(str(i)+'.',obj.marka,obj.model,obj.rocznik,obj.pojemnosc,obj.przebieg,obj.typ_skrzyni_biegow,end='\n')
            i+=1
    def dodaj(self,samochody):
        ma=input('Podaj markę ')
        mo=input('Podaj model ')
        #Zabezpieczenie przed wpisywaniem liter
        while True:
            try:
                ro=int(input('Podaj rocznik '))
                break
            except ValueError:
                print("Tylko liczby całkowite")
        while True:
            try:
                poj=int(input('Podaj pojemność '))
                break
            except ValueError:
                print("Tylko liczby całkowite")
        while True:
            try:
                prz=int(input('Podaj przebieg '))
                break
            except ValueError:
                print("Tylko liczby całkowite")
        typ=input('Podaj typ skrzyni biegów ')
        samochody.append(samochod(ma, mo, ro, poj, prz, typ))
        return samochody
    
    def zapisz(self,samochody):
        file=open("katalog.txt","w")
        for obj in samochody:
            file.write(obj.marka +' '+ obj.model +' '+ str(obj.rocznik) +' '+ str(obj.pojemnosc) +' '+ str(obj.przebieg) +' '+ obj.typ_skrzyni_biegow+'\n')
        file.close()

    def usun(self,samochody):
        i=int(input('Który usunąć? '))
        samochody.pop(i-1)
        return samochody
    
    def lista_warunek_rocznik(self,samochody):
        rok=int(input('Podaj rocznik: '))
        i=1
        for obj in samochody:
            if int(obj.rocznik) >= rok:
                print(str(i)+'.',obj.marka,obj.model,obj.rocznik,obj.pojemnosc,obj.przebieg,obj.typ_skrzyni_biegow,end='\n')
                i+=1
        return samochody
    def lista_warunek_pojemnosc(self,samochody):
        poj=int(input('Podaj pojemność: '))
        i=1
        for obj in samochody:
            if int(obj.pojemnosc) >= poj:
                print(str(i)+'.',obj.marka,obj.model,obj.rocznik,obj.pojemnosc,obj.przebieg,obj.typ_skrzyni_biegow,end='\n')
                i+=1
        return samochody
    def lista_warunek_przebieg(self,samochody):
        prz=int(input('Podaj przebieg: '))
        i=1
        for obj in samochody:
            if int(obj.przebieg) <= prz:
                print(str(i)+'.',obj.marka,obj.model,obj.rocznik,obj.pojemnosc,obj.przebieg,obj.typ_skrzyni_biegow,end='\n')
                i+=1
        return samochody
    
    def sortuj_marka(self,samochody):
        samochody.sort(key=lambda samochod: samochod.marka.upper()) # reverse=True
        return samochody
    def sortuj_model(self,samochody):
        samochody.sort(key=lambda samochod: samochod.model.upper())
        return samochody
    def sortuj_rocznik(self,samochody):
        samochody.sort(key=lambda samochod: samochod.rocznik)
        return samochody
    def sortuj_pojemnosc(self,samochody):
        samochody.sort(key=lambda samochod: samochod.pojemnosc)
        return samochody
    def sortuj_przebieg(self,samochody):
        samochody.sort(key=lambda samochod: samochod.przebieg)
        return samochody
    def sortuj_typ_skrzyni_biegow(self,samochody):
        samochody.sort(key=lambda samochod: samochod.typ_skrzyni_biegow.upper())
        return samochody

class switch(object): #Źródło: http://code.activestate.com/recipes/410692/
    def __init__(self, value):
        self.value = value
        self.fall = False
    def __iter__(self):
        """Return the match method once, then stop"""
        yield self.match
        #raise StopIteration
    def match(self, *args):
        """Indicate whether or not to enter a case suite"""
        if self.fall or not args:
            return True
        elif self.value in args:
            self.fall = True
            return True
        else:
            return False

def menu():
    print("\n\t\tKatalog samochodów\n1.Lista samochodów\n2.Lista samochodów (warunek)\n3.Sortowanie po parametrze\n4.Dodaj samochód do katalogu\n5.Usuń samochód z katalogu\n6.Wyjście\n")
    while True:
        try:
            wybor=int(input("Wybierz akcję: "))
        except ValueError:
            print("To nie cyfra")
            continue
        else:
            break
    return wybor

operacje=operacje_na_samochodach('','','','','','')
chcejeszcze=True
while(chcejeszcze):
    wybor=menu()
    for case in switch(wybor):
        if case(1):
            operacje.lista(operacje.wczytaj())
            break
        if case(2):
            print("1.Rocznik (Większy od Kryterium)\n2.Pojemność (Większa od Kryterium)\n3.Przebieg (Mniejszy od Kryterium)\n")
            warunek=int(input("Wybierz warunek: "))
            for case in switch(warunek):
                if case(1):
                    operacje.lista_warunek_rocznik(operacje.wczytaj())
                    break
                if case(2):
                    operacje.lista_warunek_pojemnosc(operacje.wczytaj())
                    break
                if case(3):
                    operacje.lista_warunek_przebieg(operacje.wczytaj())
                    break
                if case():
                    print("Traf dobrze")
                    continue
            break
        if case(3):
            print("1.Sortowanie po marce Alfabetycznie\n2.Sortowanie po modelu Alfabetycznie\n3.Sortowanie po roczniku\n4.Sortowanie po pojemności\n5.Sortowanie po przebiegu\n6.Sortowanie po typie skrzyni biegów\n")
            sortuj=int(input("Wybierz sortowanie: "))
            for case in switch(sortuj):
                if case(1):
                    operacje.lista(operacje.sortuj_marka(operacje.wczytaj()))
                    break
                if case(2):
                    operacje.lista(operacje.sortuj_model(operacje.wczytaj()))
                    break
                if case(3):
                    operacje.lista(operacje.sortuj_rocznik(operacje.wczytaj()))
                    break
                if case(4):
                    operacje.lista(operacje.sortuj_pojemnosc(operacje.wczytaj()))
                    break
                if case(5):
                    operacje.lista(operacje.sortuj_przebieg(operacje.wczytaj()))
                    break
                if case(6):
                    operacje.lista(operacje.sortuj_typ_skrzyni_biegow(operacje.wczytaj()))
                    break
                if case():
                    print("Traf dobrze")
                    continue
            break
        if case(4):
            operacje.zapisz(operacje.dodaj(operacje.wczytaj()))
            break
        if case(5):
            operacje.lista(operacje.wczytaj())
            operacje.zapisz(operacje.usun(operacje.wczytaj()))
            break
        if case(6):
            chcejeszcze=False
            print("Au revoir!")
            break
        if case():
            print("Traf dobrze")
            continue
