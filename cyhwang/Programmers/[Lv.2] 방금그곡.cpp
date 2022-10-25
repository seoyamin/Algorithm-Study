#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Music {
public:
    string note;
    string title;
    int time;
};

Music get_Music (string musicinfos);
string replace_all(string str, string from, string to);
string replace_sharp(string note);

string solution(string m, vector<string> musicinfos) {
    Music M_answer;
    M_answer.title = "(None)";
    m = replace_sharp(m);
    size_t start_pos = 0;
    
    for (int i = 0; i < musicinfos.size(); i++) {
        Music M1 = get_Music(musicinfos[i]);
        start_pos = M1.note.find(m);
        if (start_pos != string::npos) {
            if (M_answer.title == "(None)")
                M_answer = M1;
            else {
                if (M_answer.time < M1.time) {
                    M_answer = M1;
                }
            }
        }
    }
    
    return M_answer.title;
}

string replace_sharp (string note) {
    note = replace_all(note, "C#", "c");
    note = replace_all(note, "D#", "d");
    note = replace_all(note, "E#", "e");
    note = replace_all(note, "F#", "f");
    note = replace_all(note, "G#", "g");
    note = replace_all(note, "A#", "a");
    return note;
}

string replace_all(string str, string from, string to) {
	size_t start_pos = 0;

	while ((start_pos = str.find(from, start_pos)) != string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); 
	}
	return str;

}

Music get_Music (string musicinfo) {
    Music M;
    //get time
    int hour, min;
    /*if (musicinfo.substr(6,5) == "00:00") {
        hour = 24 - stoi(musicinfo.substr(0,2));
    }
    else {*/
        //hour = abs(stoi(musicinfo.substr(6,2)) - stoi(musicinfo.substr(0,2)));
    //hour = stoi(musicinfo.substr(6,2)) - stoi(musicinfo.substr(0,2));
    //}
    //min = stoi(musicinfo.substr(9,2)) - stoi(musicinfo.substr(3,2));
    //M.time = hour * 60 + min;
    M.time = stoi(musicinfo.substr(6,2)) * 60 + stoi(musicinfo.substr(9,2)) - (stoi(musicinfo.substr(0,2)) * 60 + stoi(musicinfo.substr(3,2)));
    
    
    //get length and note
    int i = musicinfo.length() - 1;
    
    while (musicinfo[i] != ',') {
        i--;
    }
    M.note = musicinfo.substr(i + 1, musicinfo.length() - i - 1);
    M.note = replace_sharp(M.note);
    
    //get title
    M.title = musicinfo.substr(12, i - 12);
    
    //덜 재생됨
    if (M.note.length() > M.time) {
        int del = M.note.length() - M.time;
        while (del > 0) {
            M.note.erase(M.note.length() - 1, 1);
            del--;
        }
    }
    
    //반복 재생됨
    string new_note = "";
    if (M.note.length() < M.time) {
        int j = 0;
        int fract = M.time % M.note.length();
        int repeat = M.time / M.note.length();
        while (repeat > 0) {
            new_note += M.note;
            repeat--;
        }
        while (fract > 0) {
            new_note += M.note[j];
            j++;
            fract--;
        }
        M.note = new_note;
    }
    
    return M;
}
