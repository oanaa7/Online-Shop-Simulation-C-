cmake_minimum_required(VERSION 3.17)
project(magazin_online)

set(CMAKE_CXX_STANDARD 14)

add_executable(magazin_online main.cpp Produs.cpp Produs.h Repo.cpp Repo.h ProdusRetur.cpp ProdusRetur.h Teste.cpp Teste.h RepoFile.cpp RepoFile.h Service.cpp Service.h UI.cpp UI.h ValidatorExceptie.h ValidatorProdus.h ValidatorProdus.cpp ValidatorProdusRetur.h ValidatorProdusRetur.cpp)