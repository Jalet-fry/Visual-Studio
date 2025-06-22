#include <string>
#include <curl/curl.h>
#include <json/json.h>
#include <iostream>
#include <C:\Users\HONOR\.vcpkg-clion\installed\x64-mingw-dynamic\include\opencv3\opencv2\opencv.hpp>
#include "c_text.h"
#include "c_image.h"
#include <iostream>
#include <string>
#include <string>
using namespace std;
#include <iostream>
#include <string>
#include <opencv2/core/types.hpp>
#include "custom.h"
#include <string>
#include "custom.h"
#include <iostream>
#include "image_api.h"
#include "Exp.h"
#include <string>
class Meme_Gen {
protected:
	int type;
public:
	int getType() const { return type; }
	void setType(const int choise) { type = choise; }
};
class C_Image : public virtual Custom {
public:
C_Image() : image_pattern(""), local_path_image("") {};
C_Image& operator=(const C_Image& other)
{
	if (this == &other)
		return *this;
	image_pattern = other.image_pattern;
	local_path_image = other.local_path_image;
	return *this;
}
const std::string &getPattern() const;
void set_pattern(const std::string &line);
std::string image_pattern;
mutable std::string local_path_image;
std::string getLocalPath() const { return local_path_image; }
void setLocalPath(const std::string& path) const { local_path_image = path; }
~C_Image() override = default;
};
class I_Settings : public C_Image {
public:
std::string image_background;
std::string image_color;
std::string getImageColor() const;
void setImageColor(const std::string& color);
I_Settings() : image_color(""), image_background("") {}
I_Settings(const C_Image& base)
: C_Image(base),
image_background(""),
image_color("") {}
I_Settings(const I_Settings& other)
: C_Image(other),
image_background(other.image_background),
image_color(other.image_color) {}
I_Settings& operator=(const I_Settings& other) {
if (this == &other)
return *this;
C_Image::operator=(other);
image_background = other.image_background;
image_color = other.image_color;
return *this;
}
void apply_settings() override{
}

void generate_meme() override {
std::string fullPrompt = image_pattern +
", background: " + image_background +
", main color: " + image_color;
Image_Api(fullPrompt);
}
std::string getBackgroundColor() const;
void setBackgroundColor(const std::string& color);
~I_Settings() override {}
};
class C_Text : public virtual Custom {
public:
std::string getMemeText() const;
void setMemeText(const std::string& text) const;
void apply_settings() override {
std::cout << "Применение настроек для изображения." << std::endl;
}
void generate_meme() override {
std::string prompt = "Helen";
std::string response;
std::cin >> response;
std::cout << "Final Answer: " << response << std::endl;
}
mutable std::string text_pattern;
};
class T_Settings : public C_Text {
private:
std::string text_background;
std::string text_font;
public:
std::string text_color;
int font_size;
const std::string getTextColor() const ;
void setTextColor(std::string color);
const std::string &getTextFont() const;
void setTextFont(const std::string& font);
int getFontSize() const;
void setFontSize(int size);
const std::string &getTextBackground() const;
void setTextBackground(const std::string &textBackground);
T_Settings() : text_color(""), text_font(""), text_background(""), font_size(12) {}
void apply_settings() override{

26

}
void generate_meme() override {
apply_settings();
C_Text::generate_meme();
}
};
class Custom : public Meme_Gen {
protected:
int meme_type;
int getMemeType() const;
public:
virtual ~Custom() = default;
Custom();
void setMemeType(int type);
virtual void generate_meme() = 0;
virtual void apply_settings() = 0;
};
std::string c_image();
std::string c_text();
void overlay();
#include <stdexcept>
#include <setjmp.h>
#include <string>
#include <iostream>
#include <thread>
//#include "overlay.h"
class Overlay;
class Exp
{
private:
	std::string report;
public:
	Exp() : report("No errors") {};
	virtual ~Exp() = default;
}};
class Numbers : public Exp
{
private:
	static jmp_buf jumpBuffer;
public:


	static int check_input();
};
class Out_of_range: public Exp
{
public:
static int out_of_range(int size);
};
class Check_server_answer: public Exp
{
public:
static std::string validate_and_resend(const std::string& prompt, int max_attempts
= 3);
};
class Overlay_validator: public Exp
{
public:
static void validate_overlay_data (Overlay& overlay);
};
int templates();
int custom();
// Функция для записи данных ответа
size_t WriteCallback_text(void* contents, size_t size, size_t nmemb, void* userp);
// Функция для отправки запроса на API
std::string getResponseFromHuggingFace(const std::string& prompt);
std::string cleanBase64String(const std::string& encoded);
size_t WriteCallback_s(void* contents, size_t size, size_t nmemb, void* userp);
std::vector<unsigned char> base64Decode(const std::string& encoded);
int Image_Api(const std::string& prompt);
class Overlay : public I_Settings, public T_Settings
{
public:
Overlay()
{
local_path_image = "";
text_pattern = "";
}
void generate_meme() override {}
void apply_settings() override {}
void do_overlay (Overlay& overlay);
~Overlay() override = default;
};

void addTextToImage(const std::string& imagePath, const std::string& text, int fontSize,
	const cv::Scalar& color) {
	cv::Mat image = cv::imread(imagePath);
	if (image.empty()) {
		std::cerr << "Ошибка: не удалось загрузить изображение!" << std::endl;
		return;
	}
	int fontFace = cv::FONT_HERSHEY_SIMPLEX;
	double fontScale = fontSize / 10.0;
	int thickness = 2;
	int baseline = 0;
	cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness,
		&baseline);
	cv::Point textOrg((image.cols - textSize.width) / 2, (image.rows + textSize.height)
		/ 2);
	cv::putText(image, text, textOrg, fontFace, fontScale, color, thickness);
	cv::imwrite(R"(D:\Proga\Turovec\Kursach\Templates\output.jpg)", image);
}

class Social_Media
{
private:
	string account_bot;
	string local_path;
	int user_id;
public:
	virtual void distributing() {}
};
class Telegram : public Social_Media{
public:
	void distributing() override
	{
	}
};
class VK : public Social_Media
{
public:
	void distributing() override
	{
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	Meme_Gen Generation;
	std::cout << "Добро пожаловать в генератор мемов! Выберите нужную функцию:\n";
	while (true) {
		std::cout << "1. Выбор шаблона;\n"
			"2. Генерация фото и текста;\n"
			"0. Выйти.";
		int choise = 0;
		switch (Numbers::check_input()) {
		case 1:
			Generation.setType(choise);
			templates();
			break;
		case 2:
			Generation.setType(choise);
			custom();
			break;
		case 0:
			std::cout << "До скорых встреч!\n";
			exit(0);
		default:
			std::cout << "Попробуйте ещё раз: \n";
			break;
		}
	}
}
