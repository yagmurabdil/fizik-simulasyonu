#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

char bilim_insani[100];

char *gezegen_adlari[8] = {
    "Merkur", "Venus", "Dunya", "Mars",
    "Jupiter", "Saturn", "Uranus", "Neptun"
};
double gezegen_ivme[8] = {
    3.70, 8.87, 9.81, 3.71,
    24.79, 10.44, 8.69, 11.15
};

void serbest_dusme() {
    double saniye;
    int i;

    printf("%s serbest dusme deneyi icin sure girmelisin(saniye cinsinden):", bilim_insani);
    while (scanf("%lf", &saniye) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("%s serbest dusme deneyi icin sure girmelisin(saniye cinsinden):", bilim_insani);
    }

    saniye = (saniye < 0) ? -saniye : saniye;

    for (i = 0; i < 8; i++) {
        char *gezegen = *(gezegen_adlari + i);
        double g = *(gezegen_ivme + i);
        double yukseklik;

        yukseklik = 0.5 * g * saniye * saniye;
        printf("%s gezegeninde yercekimi ivmesi %.2f m/s^2 oldugundan, cismin %.2f saniyede dusdugu mesafe %.6f metredir.\n",
               gezegen, g, saniye, yukseklik);
    }
}

void yukari_atis() {
    double hiz;
    int i;

    printf("%s yukari atis deneyi icin hiz girmelisin(m/s cinsinden):", bilim_insani);
    while (scanf("%lf", &hiz) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("%s yukari atis deneyi icin hiz girmelisin(m/s cinsinden):", bilim_insani);
    }

    for (i = 0; i < 8; i++) {
        char *gezegen = *(gezegen_adlari + i);
        double g = *(gezegen_ivme + i);
        double maksimum_yukseklik;

        maksimum_yukseklik = (hiz * hiz) / (2 * g);

        printf(" %s gezegeninde yercekimi ivmesi %.2f m/s^2 oldugundan cismin %.2f m/s hizla ulasabildigi maksimum yukseklik %.6f metredir. \n",
               gezegen, g, hiz, maksimum_yukseklik);
    }
}

void agirlik(){
    double kutle;
    int i;

    printf("%s agirlik deneyi icin kutle girmelisin(kg cinsinden): ", bilim_insani);
    while (scanf("%lf", &kutle) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("%s agirlik deneyi icin kutle girmelisin(kg cinsinden): ", bilim_insani);
    }

    kutle = (kutle < 0) ? -kutle : kutle;

    for (i = 0; i < 8; i++) {
        char *gezegen = *(gezegen_adlari + i);
        double g = *(gezegen_ivme + i);
        double agirlik;

        agirlik = kutle * g;

        printf("%s gezegeninde yercekimi ivmesi %.2f m/s^2 oldugundan, %.2f kg kutleli cismin agirligi %.6f N'dir.\n",
               gezegen, g, kutle, agirlik);
    }
}

void kutlecekimsel_potansiyel () {
    double kutle, yukseklik;
    int i;

    printf("%s, kutlecekimsel potansiyel enerji deneyi icin cismin kutlesini gir (kg cinsinden): ", bilim_insani);
    while (scanf("%lf", &kutle) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("%s, kutlecekimsel potansiyel enerji deneyi icin cismin kutlesini gir (kg cinsinden): ", bilim_insani);
    }

    printf("Cismin bulundugu yuksekligi gir (metre cinsinden): ");
    while (scanf("%lf", &yukseklik) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("Cismin bulundugu yuksekligi gir (metre cinsinden): ");
    }

    kutle = (kutle < 0) ? -kutle : kutle;
    yukseklik = (yukseklik < 0) ? -yukseklik : yukseklik;

    for (i = 0; i < 8; i++) {
        char *gezegen = *(gezegen_adlari + i);
        double g = *(gezegen_ivme + i);
        double potansiyel_enerji;

        potansiyel_enerji = kutle * g * yukseklik;

        printf("%s gezegeninde yercekimi ivmesi %.2f m/s^2 oldugundan, "
               "%.2f kg kutleye sahip cismin %.2f metre yukseklikteki "
               "kutlecekimsel potansiyel enerjisi %.6f joule'dur.\n",
               gezegen, g, kutle, yukseklik, potansiyel_enerji);
    }
}

void hidrostatik_basinc(void) {
    double yogunluk, derinlik;
    int i;

    printf("%s, hidrostatik basinc deneyi icin sivi yogunlugunu gir (kg/m^3): ", bilim_insani);
    while (scanf("%lf", &yogunluk) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("%s, hidrostatik basinc deneyi icin sivi yogunlugunu gir (kg/m^3): ", bilim_insani);
    }

    printf("Sivinin derinligini gir (metre): ");
    while (scanf("%lf", &derinlik) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("Sivinin derinligini gir (metre): ");
    }

    yogunluk = (yogunluk < 0) ? -yogunluk : yogunluk;
    derinlik = (derinlik < 0) ? -derinlik : derinlik;

    for (i = 0; i < 8; i++) {
        char *gezegen = *(gezegen_adlari + i);
        double g = *(gezegen_ivme + i);
        double basinc = yogunluk * g * derinlik;

        printf("%s gezegeninde yercekimi ivmesi %.2f m/s^2 oldugundan, "
               "%.2f kg/m^3 yogunlugundaki sivinin %.2f metre derinlikte "
               "uyguladigi hidrostatik basinc %.6f Pascal'dir.\n",
               gezegen, g, yogunluk, derinlik, basinc);
    }
}



void arsimet_kkuvveti() {
    double yogunluk, hacim;
    int i;

    printf("%s, Arsimet kaldirma kuvveti deneyi icin sivi yogunlugunu gir (kg/m^3 cinsinden): ", bilim_insani);
    while (scanf("%lf", &yogunluk) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("%s, Arsimet kaldirma kuvveti deneyi icin sivi yogunlugunu gir (kg/m^3 cinsinden): ", bilim_insani);
    }

    printf("Cismin sivi icinde batan hacmini gir (m^3 cinsinden): ");
    while (scanf("%lf", &hacim) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("Cismin sivi icinde batan hacmini gir (m^3 cinsinden): ");
    }

    yogunluk = (yogunluk < 0) ? -yogunluk : yogunluk;
    hacim = (hacim < 0) ? -hacim : hacim;

    for (i = 0; i < 8; i++) {
        char *gezegen = *(gezegen_adlari + i);
        double g = *(gezegen_ivme + i);
        double kaldirma_kuvveti;

        kaldirma_kuvveti = yogunluk * g * hacim;

        printf("%s gezegeninde yercekimi ivmesi %.2f m/s^2 oldugundan, "
               "%.2f kg/m^3 yogunlugundaki sivida %.4f m^3 hacmindeki cismin "
               "maruz kaldigi Arsimet kaldirma kuvveti %.6f Newton'dur.\n",
               gezegen, g, yogunluk, hacim, kaldirma_kuvveti);
    }
}

void basit_sarkac_periyodu() {
    double uzunluk;
    int i;

    printf("%s, basit sarkac periyodu deneyi icin sarkacin uzunlugunu gir (metre): ", bilim_insani);
    while (scanf("%lf", &uzunluk) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("%s, basit sarkac periyodu deneyi icin sarkacin uzunlugunu gir (metre): ", bilim_insani);
    }

    uzunluk = (uzunluk < 0) ? -uzunluk : uzunluk;

    for (i = 0; i < 8; i++) {
        char *gezegen = *(gezegen_adlari + i);
        double g = *(gezegen_ivme + i);
        double periyot;

        periyot = 2 * PI * sqrt(uzunluk / g);

        printf("%s gezegeninde yercekimi ivmesi %.2f m/s^2 oldugundan, "
               "%.2f metre uzunlugundaki sarkacin bir tam salinim periyodu %.6f saniyedir.\n",
               gezegen, g, uzunluk, periyot);
    }
}

void ip_gerilmesi( ) {
    double kutle;
    int i;

    printf("%s, sabit ip gerilmesi deneyi icin cismin kutlesini gir (kg): ", bilim_insani);
    while (scanf("%lf", &kutle) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("%s, sabit ip gerilmesi deneyi icin cismin kutlesini gir (kg): ", bilim_insani);
    }

    kutle = (kutle < 0) ? -kutle : kutle;

    for (i = 0; i < 8; i++) {
        char *gezegen = *(gezegen_adlari + i);
        double g = *(gezegen_ivme + i);
        double gerilme_kuvveti;

        gerilme_kuvveti = kutle * g;

        printf("%s gezegeninde yercekimi ivmesi %.2f m/s^2 oldugundan, "
               "%.2f kg kutleli cismin ipe uyguladigi gerilme kuvveti %.6f Newton'dur.\n",
               gezegen, g, kutle, gerilme_kuvveti);
    }
}

void asansor_deneyi() {
    double kutle, ivme;
    int yon;
    int i;

    printf("%s, asansor deneyi icin cismin kutlesini gir (kg cinsinden): ", bilim_insani);
    while (scanf("%lf", &kutle) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("%s, asansor deneyi icin cismin kutlesini gir (kg cinsinden): ", bilim_insani);
    }

    printf("%s asansor deneyi icin asansor ivmesini gir (m/s^2 cinsinden): ",bilim_insani);
    while (scanf("%lf", &ivme) != 1) {
        printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
        while (getchar() != '\n') {}
        printf("%s asansor deneyi icin asansor ivmesini gir (m/s^2 cinsinden): ",bilim_insani);
    }

    do {
        printf("Asansor hangi yonde ivmeleniyor? (1: Yukari, 2: Asagi): ");
        while (scanf("%d", &yon) != 1) {
            printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
            while (getchar() != '\n') {}
            printf("Asansor hangi yonde ivmeleniyor? (1: Yukari, 2: Asagi): ");
        }
        if (yon != 1 && yon != 2) {
            printf("Hatali secim! Lutfen sadece 1 veya 2 gir.\n");
        }
    } while (yon != 1 && yon != 2);

    kutle = (kutle < 0) ? -kutle : kutle;
    ivme  = (ivme  < 0) ? -ivme  : ivme;

    for (i = 0; i < 8; i++) {
        char *gezegen = *(gezegen_adlari + i);
        double g = *(gezegen_ivme + i);
        double etkin_agirlik;

        etkin_agirlik = (yon == 1)
                        ? kutle * (g + ivme)
                        : kutle * (g - ivme);

        printf("%s gezegeninde yercekimi ivmesi %.2f m/s^2 oldugundan, "
               "%.2f kg kutleli cismin asansorde hissettigi etkin agirlik %.6f Newton'dur.\n",
               gezegen, g, kutle, etkin_agirlik);
    }
}

int main() {
    int secim;
    char *deneyadi;

    printf("Uzayin derinliklerinde fizigi kesfetmeye hazir misin? Bu simulasyonda evrenin farkli koselerinde fizik kurallarini deneyimleme firsati bulacaksin.Hazirsan kendini bir bilim insani olarak hayal et ve adini gir:");
    scanf("%s",bilim_insani);

    printf("Harika bir isim.Tekrardan hosgeldin %s.\n",bilim_insani);
    while(1){

        do{
            printf("Simdi lutfen gerceklestirmek istedigin deneyi sec:(1-9).Eger bu maceradan cikmak istiyorsan -1 girmen yeterli\n");
            printf(" 1-SERBEST DUSME DENEYI \n 2-YUKARI ATIS DENEYI \n 3-AGIRLIK DENEYI \n 4-KUTLECEKIMSEL POTANSIYEL ENERJI DENEYI \n 5-HIDROSTATIK BASINC DENEYI\n 6-ARSIMET KALDIRMA KUVVETI DENEYI \n 7-BASIT SARKAC PERIYODU DENEYI\n 8-SABIT IP GERILMESI DENEYI \n 9-ASANSOR DENEYI \n ");

            while (scanf("%d",&secim) != 1) {
                printf("Hatali giris! Lutfen sayisal bir deger gir.\n");
                while (getchar() != '\n') {}
                printf("Lutfen secimi tekrar gir: ");
            }

            if(secim==-1){
               printf ("Program sonlandiriliyor.\n");
                exit(0);
            }

            if(secim < 1 || secim > 9)
                printf("Yanlis secim lutfen tekrar deneyiniz.\n");
        }while(secim < 1 || secim > 9);

        switch(secim){
            case 1 :
                deneyadi = "Serbest dusme deneyi";
                printf("%s basliyor.\n", deneyadi);
                serbest_dusme();
                break;

            case 2:
                deneyadi = "Yukari atis deneyi";
                printf("%s basliyor.\n", deneyadi);
                yukari_atis();
                break;

            case 3 :
                deneyadi = "Agirlik deneyi";
                printf("%s basliyor.\n", deneyadi);
                agirlik();
                break;

            case 4 :
                deneyadi = "Kutlecekimsel potansiyel enerji deneyi";
                printf("%s basliyor.\n", deneyadi);
                kutlecekimsel_potansiyel();
                break;

            case 5 :
                deneyadi = "Hidrostatik basinc deneyi";
                printf("%s basliyor.\n", deneyadi);
                hidrostatik_basinc();
                break;

            case 6:
                deneyadi = "Arsimet kaldirma kuvveti deneyi";
                printf("%s basliyor.\n", deneyadi);
                arsimet_kkuvveti();
                break;

            case 7 :
                deneyadi = "Basit sarkac periyodu deneyi";
                printf("%s basliyor.\n", deneyadi);
                basit_sarkac_periyodu();
                break;

            case 8 :
                deneyadi = "Sabit ip gerilmesi deneyi";
                printf("%s basliyor.\n", deneyadi);
                ip_gerilmesi();
                break;

            case 9:
                deneyadi = "Asansor deneyi";
                printf("%s basliyor.\n", deneyadi);
                asansor_deneyi();
                break;
        }
    }

    return 0;
}
