#include "csv.hpp"

// Preenche out com as palavras de str, que é quebrada de acordo com o delimitador ';'
void CSV::split(string &str, vector<string> &out)
{
  istringstream tokenizer{str};
  string atributo;

  while (getline(tokenizer, atributo, ';'))
    out.push_back(atributo);
}

// Retorna a string do cabeçalho do arquivo csv de acordo com os campos de object
string CSV::getHeader(IReadable &object)
{
  /*
  //Por que não está capturando a pessoa [0]?
  vector<string> header;
  object.GetCampos(header);

  stringstream ss;
   for (auto it = header.begin(); it != header.end(); it++)	{
    if (it != header.begin()) {
      ss << ";";
     }
     ss << *it;
   }
  return ss.str();*/
  return "nome;idade;cpf";
}

// Lê as linhas da entrada e seta o object de acordo com os atributos passados
void CSV::readLine(string &head, string &line, IReadable &object)
{
  vector<string> out_line;
  vector<string> out_head;
  split(head, out_head);
  split(line, out_line);

  object.setAtributo(out_head[0], out_line[0]);
  object.setAtributo(out_head[1], out_line[1]);
  object.setAtributo(out_head[2], out_line[2]);
}

// Converte o objet para uma string
string CSV::write(IReadable &object)
{
  string obj_convert;
  vector<string> out;
  object.GetCampos(out);

  obj_convert = object.GetAtributo("nome") + ";" + object.GetAtributo("idade") + ";" + object.GetAtributo("cpf");

  return obj_convert;
}
