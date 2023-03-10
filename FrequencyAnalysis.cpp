#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

class Decoder
{
private:
    
    std::string text;
    std::map<char, size_t> freq;
    std::vector<char> rusFreq;

    std::map<char, char> decodeTable;

    void setAlph()
    {
        setlocale(LC_ALL, "rus");
        freq =
         {
             {'а', 0}, {'б', 0}, {'в', 0}, {'г', 0}, {'д', 0}, {'е', 0}, {'ё', 0}, {'ж', 0},
             {'з', 0}, {'и', 0}, {'й', 0}, {'к', 0}, {'л', 0}, {'м', 0}, {'н', 0}, {'о', 0},
             {'п', 0}, {'р', 0}, {'с', 0}, {'т', 0}, {'у', 0}, {'ф', 0}, {'х', 0}, {'ц', 0},
             {'ч', 0}, {'ш', 0}, {'щ', 0}, {'ъ', 0}, {'ы', 0}, {'ь', 0}, {'э', 0}, {'ю', 0},
             {'я', 0}
         };

        }
    void setFreq()
    {
        rusFreq =
        {
            'о', 'а', 'е', 'и', 'н', 'т', 'р', 'с',
            'л', 'в', 'к', 'п', 'м', 'у', 'д', 'я',
            'ы', 'ь', 'з', 'б', 'г', 'й', 'ч', 'ю',
            'х', 'ж', 'ш', 'ц', 'щ', 'ф', 'э', 'ъ',
            'ё'
        };
    }
    void countLetters()
    {
        for (const auto &i : text)
        {
            if (i >= 'а' && i <= 'я')
                ++freq[i];
            else if (i >= 'А' && i <= 'Я')
                ++freq[i - 'а'];
            else if (i == 'ё')
                ++freq[i];
            else if (i == 'Ё')
                ++freq[i - ('Ё' - 'ё')];
        }
    }
    void createMap()
    {
        countLetters();
        std::vector<std::pair<size_t, char>> vec;

        for (auto &i : freq)
        {
            std::cout << '\n' << i.first << '\t' << i.second;
            std::pair<size_t, char> temp;
            temp.first = i.second;
            temp.second = i.first;
            vec.push_back(temp);
        }

        std::sort(vec.rbegin(), vec.rend());

        for (int i = 0; i < vec.size(); ++i)
            decodeTable.insert({ vec[i].second, rusFreq[i] });

    }
 
public:
    
    Decoder(std::string &str): text(str) { setAlph(); setFreq(); createMap(); }
    Decoder(const char *str) : text(str) { setAlph(); setFreq(); createMap(); }

    void decoding()
    {
        for (auto &i : text)
        {
            if (i >= 'А' && i <= 'Я') i -= 'а';
            if (decodeTable.find(i) != decodeTable.end())
                i = decodeTable[i];
        }
        
        std::cout << "\n\n" << text;
    }
  
};

int main()
{
    
    Decoder test =
        // Алфавит со сдвигом на 1
        "\nББбббббббббббббббббббббббббббббббббббббб"
        "\nввввввввввввввввввввввввввввввввввввввв"
        "\nгггггггггггггггггггггггггггггггггггггг"
        "\nддддддддддддддддддддддддддддддддддддд"
        "\nееееееееееееееееееееееееееееееееееее"
        "\nёёёёёёёёёёёёёёёёёёёёёёёёёёёёёёёёёёё"
        "\nжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжж"
        "\nззззззззззззззззззззззззззззззззз"
        "\nииииииииииииииииииииииииииииииии"
        "\nййййййййййййййййййййййййййййййй"
        "\nкккккккккккккккккккккккккккккк"
        "\nллллллллллллллллллллллллллллл"
        "\nмммммммммммммммммммммммммммм"
        "\nннннннннннннннннннннннннннн"
        "\nоооооооооооооооооооооооооо"
        "\nппппппппппппппппппппппппп"
        "\nрррррррррррррррррррррррр"
        "\nссссссссссссссссссссссс"
        "\nтттттттттттттттттттттт"
        "\nууууууууууууууууууууу"
        "\nфффффффффффффффффффф"
        "\nххххххххххххххххххх"
        "\nцццццццццццццццццц"
        "\nччччччччччччччччч"
        "\nшшшшшшшшшшшшшшшш"
        "\nщщщщщщщщщщщщщщщ"
        "\nъъъъъъъъъъъъъъ"
        "\nыыыыыыыыыыыыы"
        "\nьььььььььььь"
        "\nэээээээээээ"
        "\nюююююююююю"
        "\nяяяяяяяяя"
        "\nаааааааа";
    
    test.decoding();

    std::string str0 =
        "Есыог сфхсусйрс, хлшс, дзфыцпрс фхцтгв, тоюев тс нспргхз, фосерс тулкугн, тулелжзрлз, г зжлрфхезррюп кецнсп, еюжгегеылп зз желйзрлз, "
        "дюо ысусш ргнлжнл, тулнгфгеызмфв н ёсоспц хзоц.Сжргнс лпзррс ахсх лфъзкгбьз хлшлм, зжег цоселпюм ызозфх угкдцжло езжяпгнг, г псйзх, хсоянс еюуего лк тсоцфрг, "
        "е нсхсусп ср пзурс нсоюшгофв, фосерс тсёуцйзррюм е дзкжсррцб хсря, елфвьлм пзйжц жрсп л тсезушрсфхяб фтснсмрсёс псув, фузжл озёсрянс лкелегбьлшфв рлхзм есжсусфозм. "
        "Ср рз тсызезолофв, жгйз рз жусёрцо.Жзецынг тсжтсушрцог долйз, фдусфлог ргнлжнц, пзжозррс, рзузылхзоярс стзуогфя нсозрсп с нугм осйг.Ср ргдобжго кг рзм лк - "
        "тсж стцьзррюш узфрлщ, рз еюжгегв фздв.Жзецынг сфхсусйрс тсжрвогфя рг тсфхзоя, озёог рг рзёс, сдшегхлог дзжугпл.Стлугвфя рг ргтувйзррюз уцнл, фнсоякрцог тс зёс "
        "олщц есосфгпл.Есосфю тгшол успгынсм.Узылхзоярс л нгн дю рзхзутзолес ргносрлогфя, нсфрцогфя фсфсънсп зёс езнг, ьзнл, ёцд.Ср цоюдрцофв, пзжозррс, сфхсусйрс, рзйрс "
        "екво зз уцнл е фесл.Срг еютувплогфя, цфнсоякгв сх зёс тгоящзе, оцълфхгв, тсжфезъзрргв л сх ахсёс фезхг рзъзхнгв е хцпгррсп схдозфнз кгул.Ср тсызезолофв, рс срг "
        "узылхзоярюп ргйлпсп сдзлш уцн сфхгрселог зёс л озёнлпл, рс ргфхсмълеюпл желйзрлвпл дзжзу жсдлогфя схезхг.Ср схезхло.Срг цйз рз лкдзёгог зёс уцн, схнлрцог ёсосец, "
        "ефхувшрцог есосфгпл.Зз нсйг дюог шсосжрсм л тсугклхзоярс ёогжнсм.Ёогкг, нсхсуюз ср целжзо, нсёжг срг тулдолклог фесз олщс н зёс олщц, дюол сёуспрюпл л хзпрюпл, "
        "нгн ёогкг уцфгонл.Тснгълегвфя, ср цхсрцо е успгынсесп псуз, г срс екдцуолос л кгыцпзос, тсхзуве тснсм.Тсхсп ёсесулол, ъхс ъзосезн ахсх тулызо ф фзезуг, "
        "фс фхсусрю Нгргхълнсеюш есусх.Ср ызо, г ргеябъзррцб осыгжя езо тсж цкжщю.Ргжелёгофв езъзу, л огенл нгргхълнсе л ысурлнсе цйз кгнуюолфя, г цосънг стцфхзог.Дюос хзтос, "
        "рс рг ъзосезнз дюо ъзурюм тогь, ргнлрцхюм рг тозъл.Ср сдугьго рг фздв ерлпгрлз.Тцхрлн сфхгрселофв тзузж хугнхлусп «Фхгугв Тузлфтсжрвв», тсфхсво рзпрсёс, тулфоцылегвфя "
        "н ёцоц ёсосфсе.Хугнхлу, нгн ефзёжг е ахс еузпв, дюо тсоср ргусжц.Рзкргнспзщ рз есызо е «Фхгуцб Тузлфтсжрбб», г тсезо осыгжя жгояыз, ерлк тс цосънз н жуцёспц хугнхлуц, "
        "тспзряыз, нсхсуюм ргкюегофв «Ц Олфг».Кжзфя дюос тцфхсегхс – хугнхлу тсояксегофв рз оцъызм узтцхгщлзм.Хугнхлуьлн тсжрво ёсосец сх дсънл ф фсозрюпл сёцущгпл л фпзуло ёсфхв "
        "екёовжсп.Ъцйгн, ефз зьз е тогьз, фхсво тзузж фхсмнсм хезужс, рзтсжелйрс л псоъго.– Ъхс тсжгхя ? – Тлег, – фнгкго рзкргнспзщ.Ёсосф дюо рзтулвхрюм.Хугнхлуьлн еюхзу уцнл "
        "тсосхрврюп чгухцнсп л ргтсорло ьзудгхцб ёолрврцб нуцйнц.Рзкргнспзщ рз дюо фхгу, рс есосфю ц рзёс дюол тсъхл фсезуызррс дзоюпл.Тсж тогьсп ср рсфло тсхзухцб нсйгрцб нцухнц "
        "фс ырцусенсм ц ёсуог л рг уцнгегш.Нсёжг фдусфло тогь, фхгос елжрс, ъхс рг узпрз кг фтлрсм ц рзёс елфлх пзъ.Рлъзёс фхугррсёс е ахсп рз дюос, е Еюклпз тсъхл ефз шсжлол ф "
        "суцйлзп, тугежг, рлнхс рз рсфло пзъ рг фтлрз, фосерс оцн лол нсоъгр.Рзкргнспзщ рз тулфзо н фхсоц, ёжз угфтсосйлолфя рзпрсёсълфозррюз тсфзхлхзол, г сфхгофв ц фхсмнл, "
        "ерлпгхзоярс лкцъгв екёовжсп хугнхлуьлнг.– Льц нспргхц рг рсъя, – тусёсесуло ср, схшоздрце лк нуцйнл.– Рзхц, – дцунрцо хугнхлуьлн, ёовжв рг сдценц ёсфхв, кгтюозррцб л "
        "ёувкрцб.– Фтусфлхз е «Фхгусм Тузлфтсжрзм».– В дю шсхзо кжзфя.– Рзхц.– Хугнхлуьлн ргнсрзщ угфтскрго еюёсесу рзкргнспщг.Улелзщ.– В кгтогъц, – хлшс л нгн дю рзцезузррс "
        "фнгкго ъцйгн.Хсёжг - хс л ргъгогфя ахг тгфнцжргв лфхсулв.Увдсм езуклог, ф пспзрхг тсвеозрлв ъцйгнг рз фтцфнгеылм ф рзёс цёубпсёс екёовжг, ефхго л тсжсызо н фхсмнз.Жесз ";
        "зёс жуцйнсе ефхгол ыгёгш е жецш тскгжл.";
}

