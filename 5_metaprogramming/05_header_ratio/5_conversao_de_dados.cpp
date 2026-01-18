#include <iostream>
#include <iomanip>
#include <string>
#include <functional>
#include <map>
#include <ratio>

// Definindo as razões ExaBytetas (todas base 1024 = 2^10)
using r1024 = std::ratio<1LL << 10, 1>; // 1024/1

using KiloByte = std::ratio_multiply<r1024, std::ratio<1>>;
using MegaByte = std::ratio_multiply<r1024, KiloByte>;
using GigaByte = std::ratio_multiply<r1024, MegaByte>;
using TeraByte = std::ratio_multiply<r1024, GigaByte>;
using PetaByte = std::ratio_multiply<r1024, TeraByte>;
using ExaByte = std::ratio_multiply<r1024, PetaByte>;

// Template para converter com ratio em tempo de compilação
template <typename FromRatio, typename ToRatio, typename T>
constexpr long double convertRatio(T value)
{
   // Converte usando a razão ExaByteta entre as unidades
   return static_cast<long double>(value) * (static_cast<long double>(FromRatio::num) / FromRatio::den) / (static_cast<long double>(ToRatio::num) / ToRatio::den);
}

// Função prática com mapa de unidades
class DataConverter
{
public:
   static long double convert(long double value, const std::string &from, const std::string &to)
   {
      static const std::map<std::string, std::function<long double(long double)>> converters = {
          {"B", [](auto v)
           {
              return convertRatio<std::ratio<1>, std::ratio<1>>(v);
           }},

          {"KB", [](auto v)
           {
              return convertRatio<KiloByte, std::ratio<1>>(v);
           }},

          {"MB", [](auto v)
           {
              return convertRatio<MegaByte, std::ratio<1>>(v);
           }},

          {"GB", [](auto v)
           {
              return convertRatio<GigaByte, std::ratio<1>>(v);
           }},

          {"TB", [](auto v)
           {
              return convertRatio<TeraByte, std::ratio<1>>(v);
           }},

          {"PB", [](auto v)
           {
              return convertRatio<PetaByte, std::ratio<1>>(v);
           }},

          {"EB", [](auto v)
           {
              return convertRatio<ExaByte, std::ratio<1>>(v);
           }}};

      auto fromBytes = converters.at(from)(value);
      auto toValue = fromBytes / (converters.at(to)(1.0)); // 1 unidade destino → quantos bytes?
      return toValue;
   }
};

int main(int argc, char **argv)
{
   std::cout << std::fixed << std::setprecision(6);
   std::cout << "=== Conversor usando std::ratio (C++20) ===\n\n";

   // Exemplos diretos com ratio (compilador sabe que é ExaByteto!)
   std::cout << "2500 MB em GB: " << convertRatio<MegaByte, GigaByte>(2500.0) << " GB\n";
   std::cout << "5 GB em MB: " << convertRatio<GigaByte, MegaByte>(5.0) << " MB\n";
   std::cout << "0.75 TB em GB: " << convertRatio<TeraByte, GigaByte>(0.75) << " GB\n";
   std::cout << "15000 KB em MB: " << convertRatio<KiloByte, MegaByte>(15000.0) << " MB\n";
   std::cout << "1 PB em TB: " << convertRatio<PetaByte, TeraByte>(1.0) << " TB\n\n";

   // Usando a classe com interface amigável
   auto teste = DataConverter::convert(2560, "MB", "GB");
   std::cout << "2560 MB = " << teste << " GB (usando classe)" << '\n';

   // Outro exemplo
   std::cout << "1 EB em PB: " << convertRatio<ExaByte, PetaByte>(1.0) << " PB" << '\n';

   return 0;
}
