# Geliştirilen Kod'un Zaman Karmaşıklığı

•   **generate()** fonksiyonu her döngü adımında *a* dizisinin *i*'inci elemanına rastgele bir tamsayı atanır. Bu işlem *rand()* fonksiyonu ile gerçekleşir. Rastgele tamsayının değeri  2 x MAX_W 2 da küçük olana kadar *%* opertörü ile mod alınır. Burada MAX_W bir sabit değeri ifade eder. Mod alınan değer, MAX_W'ın negatif değeriyle MAX_W'ın pozitif değeri arasında olur. Bu elde edilen rastgele değer, a dizisinin i'inci elemanına atanır. Döngü sonlanasıya kadar devam eder bu yüzden dizi boyutu kadar çalışacağı için yani n kadar çalıştığından  zaman karmaşıklığı `O(n)` olur.

•   **quickSortSiralama()** fonksiyonu, Quick sort kullanıldığı için zaman karmaşıklığı O(nlogn) dir. While döngüleri ile i ve j değerleri karşılaştırılarak pivot elemanın konumu bulunmaya çalışılır burada *n* kez işlem yapılır bulunduktan sonra parçalaya parçalaya elemanlara bakılacağı için *nlog** kez işlem yapılır. Sonuç olarak zaman karmaşıklığı `O(nlogn)` olur.

•   **pozitifToplamOrtalamaBul** fonksiyonu bir döngü başlatarak Her döngü adımında, mevcut current_sum değeri ile *a* dizisinin *i'inci* elemanı toplanır. Bu toplamın sonucu pozitif ise, *current_sum* bu değere eşitlenir. Eğer toplam negatif veya sıfır ise, *current_sum* sıfıra eşitlenir. current_sum değeri, t'den büyükse, t'ye current_sum değeri atanır. Aynı zamanda count bir artırılır. Bu, en büyük pozitif toplam değerini ve kaç adet pozitif toplam olduğunu takip etmek için kullanılır.Döngü sonlandığında, *t* değeri en büyük pozitif toplam değerini, count değeri ise kaç adet pozitif toplam olduğunu temsil eder.Fonksiyon, t'nin count ile bölünerek elde edilen ortalama pozitif toplam değerini döndürür ve yine dizi boyutu kadar yani n kadar çalışacağı için zaman karmaşıklığı `O(n)` olur.

•   **floydWarshall()** fonksiyonun da Floyd-Warshall kullanıldığı için `O(n^3)` olur.

•   **quickSortSiralamaPrint()** 1 for döngüsü olduğu için n kez çalışır ve zaman karmaşıklığı `O(n)`, **pozitifMaxBulPrint()**, **floydWarshallPrint()** her iki fonksiyonda da 2 tane for döngüsü olduğu için her iki fonksiyonların da zaman karmaşıkları `O(n^2)` dir.

Bu hesaplamalar sonucunda genel olarak zaman karmaşıklığı: 
O(n) + O(n^2) + O(n) + O(n^3) + O(n) + O(n^2) + O(n^2) = O(n^3) olur.

**Toplam zaman karmaşıklığı** aynı `O(n^3)` şeklinde kalacaktır. Çünkü Floyd-Warshall algoritması diğer kullanılan algoritmalardan daha yüksek karmaşıklığa sahiptir. Ayrıca Quick Sort algoritması kodun çalışmasını hızlandırmasında etkili ve verimli bir kullanım sağlamıştır.

