#include "schedule.hpp"

Schedule::Schedule(){
    name = "";
    appointments = {};
    number_of_appointments = 0;
    keepfile_base_index = this->get_keepfile_size();
}
Schedule::Schedule(std::string n){
    name = n;
    appointments = {};
    number_of_appointments = 0;
    keepfile_base_index = this->get_keepfile_size();
}
Schedule::Schedule(std::string n, Appointment* app){
    name = n;
    appointments.push_back(app);
    number_of_appointments = 1;
    keepfile_base_index = this->get_keepfile_size();
}
void Schedule::add_appointment(Appointment* app){
    appointments.push_back(app);
    number_of_appointments++;
}
std::vector<Appointment*> Schedule::get_all_appointments(){
    return appointments;
}
std::vector<Appointment*> Schedule::occurs_on(int y, int m, int d, bool show_details, std::ostream& out){
    std::vector<Appointment*> matched_appts = {};
    int count = 0;
    for (int i = 0; i < appointments.size(); i++){
        if (appointments[i]->occurs_on(y, m, d, false, out)){
            matched_appts.push_back(appointments[i]);
            count++;
        }
    }
    if (show_details && (&out == &std::cout)){
        out << count << " appointments found. " << std::endl;
        if (count > 0){
            for (int i = 0; i < matched_appts.size(); i++){
                if (i == 0) { matched_appts[i]->display_appt(out); }
                else { matched_appts[i]->display_description(out); }
            }
        }
    }
    if (&out != &std::cout){
        for (int i = 0; i < matched_appts.size(); i++){
            matched_appts[i]->display_bare_appt(out);
        }
    }
    return matched_appts;
}
void Schedule::store_all(std::ostream& out){
    for (int i = 0; i < appointments.size(); i++){
        appointments[i]->display_bare_appt(out);
    }
}
void Schedule::save_appointments(std::vector<Appointment*> appts, bool file_empty, std::string search_tag){
    const char *prefix = "/Users/christianmeyer";
    std::string dir_string = "cpp/ch8/P7_8_9/P7_8_9/temp_files/" + search_tag;
    const char *dir = dir_string.c_str();
    std::string file_name = tempnam(prefix, dir);
    saved_files.push_back(file_name);
    
    std::ofstream out;
    out.open(keepfile, std::ios::app);
    out << file_name << std::endl;
    out.close();
    
    if (file_empty){
        std::ofstream fout;
        fout.open(saved_files[0], std::fstream::in | std::fstream::out | std::fstream::trunc);
        for (int i = 0; i < appts.size(); i++){
            appts[i]->display_bare_appt(fout);
        }
    }
    saved_appointments.push_back(appts); // This way there is no need to reformat the file output to make new Appointment pointers or new vectors
}
void Schedule::get_saved_appointments(int index){
    //std::cout << "FILENAME: " << saved_files[index] << std::endl;
    
    // wonder why 'length = fin.end'>2 yet 'seekg(0, fin.end)' is able to shift seekg so that #tellg() gives 225. Maybe fin not sure what end until it has moved 'length' positions until it cannot read more data. 2, because the pointer must have lookahead - binary nodes?
    /*
    fin.seekg(0, fin.end);
    int length = fin.tellg();
    fin.seekg(0, fin.beg);
    std::cout << "length = " << length << std::endl;
    char* buffer = new char[length];
    fin.read(buffer, length);
    std::cout << "buffer: \n" << buffer << std::endl;
    std::cout << "endbuffer\n" << std::endl;
    fin.close();
    fin.open(saved_files[index]);
    */
    std::ifstream fin(saved_files[index]);
    std::string full_line = "";
    std::string line1 = "", line2 = "", line3 = "";
    
    std::vector<std::vector<std::string> > saved_appt;
    //std::vector<std::string> lines;
    
    while(std::getline(fin, line1, '|')){
        std::vector<std::string> appt;
        
        std::getline(fin, line2, '\n');
        full_line = line1 + "|" + line2;
        for (int i = 0; i < line1.size(); i++){
            if (line1[i] == '-'){
                line3 = line1.substr(i+2, line1.size()-(i+3));
                line1 = line1.substr(0, i-2);
            }
        }
        line2 = line2.substr(1, line2.size()-1);
        appt.push_back(line1);
        appt.push_back(line2);
        appt.push_back(line3);
        saved_appt.push_back(appt);
    }

    saved_appointment_fields.push_back(saved_appt);
    fin.close();
}
std::string Schedule::get_saved_file_name(int index){
    return saved_files[index];
}
std::vector<std::vector<std::string> > Schedule::get_saved_fields(int index){
    return saved_appointment_fields[index];
}
std::string Schedule::get_keepfile_name(int index, bool include_past_saves){
    if (!include_past_saves){
        index += keepfile_base_index;
    }
    std::vector<std::string> keep_filenames;
    std::string file;
    std::ifstream in(keepfile);
    while (!in.eof()){
        getline(in, file);
        keep_filenames.push_back(file);
    }
    return keep_filenames[index];
}
int Schedule::get_keepfile_size(){
    std::ifstream in(keepfile);
    std::string file = "";
    int i = 0;
    while ( std::getline(in, file, '\n') ){
        ++i;
    }
    return i;
}
int Schedule::get_keepfile_base_index() const{
    return keepfile_base_index;
}

