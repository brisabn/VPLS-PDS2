#include "pessoa.hpp"

// Imprime os dados das pessoas para o stream out
void Pessoa::print(ostream &out)
{
  out << "(nome = " << this->nome << ", idade = " << this->idade << ", CPF = " << this->cpf << ")";
}

// Preenche out com os atributos de Pessoa
void Pessoa::GetCampos(vector<string> &out)
{
  ostringstream idade_, cpf_;
  idade_ << this->idade;
  cpf_ << this->cpf;

  out.push_back(this->nome);
  out.push_back(idade_.str());
  out.push_back(cpf_.str());
}

// Inicializa os atributos de Pessoas de acordo com a key do atributo
void Pessoa::setAtributo(string key, string valor)
{
  if (key == "nome")
    this->nome = valor;
  if (key == "idade")
    this->idade = stoi(valor);
  if (key == "cpf")
    this->cpf = stoul(valor);
}

// Retorna o valor do atributo de acordo com a key do atributo
string Pessoa::GetAtributo(string key)
{
  ostringstream idade_, cpf_;
  idade_ << this->idade;
  cpf_ << this->cpf;

  if (key == "nome")
    key = this->nome;
  if (key == "idade")
    key = idade_.str();
  if (key == "cpf")
    key = cpf_.str();

  return key;
}

// Duas pessoas são iguais se possuem o mesmo cpf
bool Pessoa::operator==(Pessoa &rhs)
{
  return rhs.cpf == cpf;
}