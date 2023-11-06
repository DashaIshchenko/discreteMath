namespace lab6
{
	internal class Program
	{
		static void Main(string[] args)
		{
			while (true)
			{
				Console.Clear();
				int[,] matrix = { };
				int choice = InputIntNumber("Вы можете завершить программу (введите 0)\n\n" +
					"Считать матрицу из файла (введите 1-8)\n\n" +
					"Ваш выбор: ");
				switch (choice)
				{
					case 0:
					{
						Environment.Exit(0);
						break;
					}
					case 1:
					{
						matrix = ReadMatrix("../../../files/m1.txt");
						break;
					}
					case 2:
					{
						matrix = ReadMatrix("../../../files/m2.txt");
						break;
					}
					case 3:
					{
						matrix = ReadMatrix("../../../files/m3.txt");
						break;
					}
					case 4:
					{
						matrix = ReadMatrix("../../../files/m4.txt");
						break;
					}
					case 5:
					{
						matrix = ReadMatrix("../../../files/m5.txt");
						break;
					}
					case 6:
					{
						matrix = ReadMatrix("../../../files/m6.txt");
						break;
					}
					case 7:
					{
						matrix = ReadMatrix("../../../files/m7.txt");
						break;
					}
					case 8:
					{
						matrix = ReadMatrix("../../../files/m8.txt");
						break;
					}

					default:
					{
						Console.WriteLine("Такого файла не существует");
						break;
					}
				}
				if (choice < 9 && choice > 0)
				{
					Relation set = new Relation(matrix);
					Console.WriteLine(set.Property);
				}
				Console.ReadKey(true);
			}
		}

		static int[,] ReadMatrix(string path)
		{
			string[] st;
			string[] row = File.ReadAllLines(path);
			int[,] matrix = new int[6, 6];
			for (int i = 0; i < 6; ++i)
			{
				Console.WriteLine(row[i]);
				st = row[i].Split(" ");
				for (int j = 0; j < 6; ++j)
				{
					matrix[i, j] = int.Parse(st[j]);
				}
			}
			return matrix;
		}

		class Relation
		{
			private int[,] matrix;
			private string properties;
			public Relation(int[,] mat)
			{
				matrix = mat;
				properties = "";
				DetermineProperties();
			}
			public string Property
			{
				get => properties;
			}
			private void DetermineProperties()
			{
				if (IsReflexive())
					properties = String.Concat(properties, "\nРефлексивно");
				else if (IsAntiReflexive())
					properties = String.Concat(properties, "\nАнтирефлексивно");
				else
					properties = String.Concat(properties, "\nНе рефлексивно и не антирефлексивно");
				if (IsSymmetric())
					properties = String.Concat(properties, "\nСимметрично");
				else if (IsAntiSymmetric())
				{
					if (IsAsymmetric())
						properties = String.Concat(properties, "\nАсимметрично");
					else
						properties = String.Concat(properties, "\nАнтисимметрично");
					
				}
				else
					properties = String.Concat(properties, "\nНе обладает свойствами (анти)симметричности");
				if (IsTransitive())
					properties = String.Concat(properties, "\nТранзитивно");
				else
					properties = String.Concat(properties, "\nНе транзитивно");
				if (IsConnected())
					properties = String.Concat(properties, "\nСвязно");
				else
					properties = String.Concat(properties, "\nНесвязно");
			}

			private bool IsReflexive()
			{
				for (int i = 0; i < matrix.GetLength(0); ++i)
				{
					if (matrix[i, i] == 0)
						return false;
				}
				return true;
			}
			private bool IsAntiReflexive()
			{
				for (int i = 0; i < matrix.GetLength(0); ++i)
				{
					if (matrix[i, i] == 1)
						return false;
				}
				return true;
			}
			private bool IsSymmetric()
			{
				for (int i = 0; i < matrix.GetLength(0); ++i)
				{
					for (int j = 0; j < matrix.GetLength(1); ++j)
					{
						if ((matrix[i, j] != matrix[j, i]) && (i != j))
							return false;
					}
				}
				return true;
			}
			private bool IsAntiSymmetric()
			{
				for (int i = 0; i < matrix.GetLength(0); ++i)
				{
					for (int j = 0; j < matrix.GetLength(1); ++j)
					{
						if ((matrix[i, j] == 1) && (matrix[j, i] != 0) && (i != j))
							return false;
					}
				}
				return true;
			}

			private bool IsAsymmetric()
			{
				for (int i = 0; i < matrix.GetLength(0); ++i)
				{
					for (int j = 0; j < matrix.GetLength(1); ++j)
					{
						if (i == j)
						{
							if (matrix[i, i] != 0)
								return false;
						}
						else if ((matrix[i, j] == 1) && (matrix[j, i] != 0) && (i != j))
							return false;
					}
				}
				return true;
			}

			private bool IsTransitive()
			{
				for (int i = 0; i < matrix.GetLength(0); ++i)
				{
					for (int j = 0; j < matrix.GetLength(1); ++j)
					{
						if (matrix[i, j] == 1)
						{
							for (int k = 0; k < matrix.GetLength(1); ++k)
							{
								if ((matrix[i, k] == 0) && (matrix[j, k] == 1))
									return false;
							}
						}
					}
				}
				return true;
			}
			private bool IsConnected()
			{
				for (int i = 0; i < matrix.GetLength(0); ++i)
				{
					for (int j = 0; j < matrix.GetLength(1); ++j)
					{
						if ((matrix[i, j] != 1) && (matrix[j, i] != 1) && (i != j))
							return false;
					}
				}
				return true;
			}
		}
		static int InputIntNumber(string msg = "")
		{
			bool isNumber;
			string inputLine;
			int res;
			Console.Write(msg);
			do
			{
				inputLine = Console.ReadLine();
				isNumber = int.TryParse(inputLine, out res);
				if (!isNumber)
					Console.Write("Ошибка! Введите число\n" + msg);

			} while (!isNumber);
			return res;
		}
	}
}