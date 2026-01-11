module projetoc3;
import std::io;

int[] ys = {3,58,48,56,20,25,11,80,72,9,27,51,99,22,16,82,84,8,41,74,65,66,54,70,93,88,46,49,40,57,15,67,61,79,85,26,21,63,77,30,38,100,47,14,73,4,36,35,39,50,1,12,1,33,7,62,23,94,18,75,91,19,71,68,89,31,81,76,78,87,53,6,55,59,37,92,43,98,34,97,45,44,13,69,42,96,29,10,5,90,28,2,83,95,52,17,86,24,32,60,64};

fn int main(String[] args)
{
  int contador = 0;
  for (int i = 1; i <= 100; i++){contador ^= i;}

  foreach (v : ys) {contador ^= v;}

  int duplicado = 0;
  foreach(v : ys)
  {
      if (v == contador)
      {
          duplicado = v;
          break;
      }
  }
  if (duplicado == 0) duplicado = contador ^ 1;

//  String saida = string::format("Duplicados: %s", duplicado);
//  io::printn(saida);

  io::printf("Duplicados: %d\n", duplicado);
  io::printn(duplicado);
  return 0;
}


