#ifndef CIPHERSETTINGS_H
#define CIPHERSETTINGS_H

#include <string>

class CipherSettings
{
public:
    CipherSettings();

    enum KeyFormats
    {
        Passphrase,
        RawKey
    };

    KeyFormats getKeyFormat() const;
    void setKeyFormat(const KeyFormats &value);

    std::string getPassword() const;
    void setPassword(const std::string &value);

    int getPageSize() const;
    void setPageSize(int value);

    int getKdfIterations() const { return kdfIterations; }
    void setKdfIterations(int value) { kdfIterations = value; }

    std::string getHmacAlgorithm() const { return hmacAlgorithm; }
    void setHmacAlgorithm(const std::string &value) { hmacAlgorithm = value; }

    std::string getKdfAlgorithm() const { return kdfAlgorithm; }
    void setKdfAlgorithm(const std::string &value) { kdfAlgorithm = value; }

    static KeyFormats getKeyFormat(int rawKeyFormat);

private:
    KeyFormats keyFormat;
    std::string password;
    int pageSize;
    int kdfIterations;
    std::string hmacAlgorithm;
    std::string kdfAlgorithm;
};

#endif // CIPHERSETTINGS_H
